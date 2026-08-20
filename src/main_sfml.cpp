#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

int main()
{
    sf::Font font;
    font.loadFromFile("arial.ttf");
    std::cout << "STARTED\n" << std::flush;
    Engine engine;

    sf::RenderWindow window(sf::VideoMode(800, 600), "AtmosphereSim");

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> xDist(0, 800);
    std::uniform_real_distribution<float> yDist(50, 200);

    std::vector<sf::Vector2f> cloudPositions;
    for (int i = 0; i < 20; i++)
    {
        cloudPositions.push_back({xDist(gen), yDist(gen)});
    }

    std::vector<sf::Vector2f> raindrops;
    for (int i = 0; i < 200; i++)
    {
        raindrops.push_back({xDist(gen), yDist(gen)});
    }

    sf::Color currentSkyColor(0, 120, 255);

    bool lightning = false;
    int lightningTimer = 0;
    sf::Text infoText;
    infoText.setFont(font);
    infoText.setCharacterSize(18);
    infoText.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        static int simCounter = 0;
        simCounter++;

        if (simCounter >= 10) // adjust speed here
        {
            engine.UpdateSystems();
            simCounter = 0;
        }

        static int frameCounter = 0;
        frameCounter++;

        if (frameCounter >= 60) // ~1 second
        {
            engine.AdvanceTime(); // we’ll add this
            frameCounter = 0;
        }

        float temp = engine.GetTemperature();
        std::string weather = engine.GetWeather();

        if (weather == "Stormy")
        {
            if (rand() % 200 == 0)
            {
                lightning = true;
                lightningTimer = 2;
            }
        }

        int targetRed = std::min(255, (int)(temp * 8));
        int targetBlue = 255 - targetRed;

        sf::Color targetColor;

        if (weather == "Rainy" || weather == "Stormy")
        {
            targetColor = sf::Color(targetRed / 2, 80, targetBlue / 2);
        }
        else
        {
            targetColor = sf::Color(targetRed, 120, targetBlue);
        }

        if (weather == "Rainy" || weather == "Stormy")
        {
            window.clear(currentSkyColor);
            if (engine.GetHumidity() > 80)
            {
                sf::RectangleShape fog(sf::Vector2f(800, 600));
                fog.setFillColor(sf::Color(220, 220, 220, 60));
                window.draw(fog);
            }
        }
        else
        {
            window.clear(currentSkyColor);
        }

        int hour = engine.GetHour();

        float dayFactor;

        if (hour >= 6 && hour <= 18)
            dayFactor = 1.0f;
        else if (hour < 6)
            dayFactor = 0.2f + (hour / 6.0f) * 0.8f;
        else
            dayFactor = 0.2f + ((24 - hour) / 6.0f) * 0.8f;

        targetColor.r *= dayFactor;
        targetColor.g *= dayFactor;
        targetColor.b *= dayFactor;

        float speed = 0.02f;

        currentSkyColor.r += (targetColor.r - currentSkyColor.r) * speed;
        currentSkyColor.g += (targetColor.g - currentSkyColor.g) * speed;
        currentSkyColor.b += (targetColor.b - currentSkyColor.b) * speed;

        float clouds = engine.GetCloudDensity();
        int desiredCount = clouds / 5;

        while (cloudPositions.size() < desiredCount)
        {
            cloudPositions.push_back({xDist(gen), yDist(gen)});
        }

        while (cloudPositions.size() > desiredCount)
        {
            cloudPositions.pop_back();
        }

        float rainSpeed = (weather == "Stormy") ? 15.0f : 5.0f;
        float wind = engine.GetWind();

        int rainCount = (weather == "Stormy") ? 300 : 200;

        if (weather == "Rainy" || weather == "Stormy")
        {
        for (int i = 0; i < rainCount; i++)
            {
                auto& drop = raindrops[i];
                drop.y += rainSpeed;
                drop.x += wind * 0.1f;

                if (drop.y > 600 || drop.x > 800 || drop.x < 0)
                {
                    drop.y = 0;
                    drop.x = xDist(gen);
                }

                sf::RectangleShape rain(sf::Vector2f(2, 15));
                rain.setFillColor(sf::Color(180, 180, 255));
                rain.setPosition(drop);

                window.draw(rain);
            }
        }


        for (auto& pos : cloudPositions)
        {
            float cloudSpeed = (weather == "Stormy") ? 0.01f : 0.005f;
            pos.x += wind * cloudSpeed;

            if (pos.x > 800)
                pos.x = -50;
        }

        for (auto& pos : cloudPositions)
        {
            sf::CircleShape cloud(30);
            cloud.setFillColor(sf::Color(200, 200, 200));
            cloud.setPosition(pos);

            window.draw(cloud);
        }

        if (lightning)
        {
            sf::RectangleShape flash(sf::Vector2f(800, 600));
            flash.setFillColor(sf::Color(255, 255, 255, 150));
            window.draw(flash);

            lightningTimer--;
            if (lightningTimer <= 0)
                lightning = false;
        }
        std::string info =
        "Hour: " + std::to_string(hour) +
        " Temp: " + std::to_string((int)temp) +
        " Weather: " + weather;

        infoText.setString(info);
        infoText.setPosition(10, 10);

        window.draw(infoText);

        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}