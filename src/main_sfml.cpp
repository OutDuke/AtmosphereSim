#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

int main()
{
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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        engine.UpdateSystems();

        float temp = engine.GetTemperature();
        std::string weather = engine.GetWeather();
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
        }
        else
        {
            window.clear(currentSkyColor);
        }
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

        float rainSpeed = (weather == "Stormy") ? 10.0f : 5.0f;

        if (weather == "Rainy" || weather == "Stormy")
        {
            for (auto& drop : raindrops)
            {
                drop.y += rainSpeed;

                if (drop.y > 600)
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

        float wind = engine.GetWind();

        for (auto& pos : cloudPositions)
        {
            pos.x += wind * 0.005f;

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

        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}