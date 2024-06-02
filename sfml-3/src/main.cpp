#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameLogic.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const float width = 100.0f;
    const float height = 100.0f;
    const int fpsMax = 60;

    GameLogic gameLogic(screenWidth, screenHeight, width, height, fpsMax); // Create GameLogic object

    gameLogic.loop();

    return 0;
}
