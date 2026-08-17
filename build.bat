g++ src/main_sfml.cpp src/Engine.cpp src/TemperatureSystem.cpp src/HumiditySystem.cpp src/WindSystem.cpp src/CloudSystem.cpp src/WeatherSystem.cpp src/TimeSystem.cpp ^
-Iinclude ^
-I"C:/Users/outduke/Downloads/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/include" ^
-L"C:/Users/outduke/Downloads/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/lib" ^
-lsfml-graphics -lsfml-window -lsfml-system ^
-o AtmosphereSim.exe