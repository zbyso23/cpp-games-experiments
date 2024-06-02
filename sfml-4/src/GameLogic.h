#include <SFML/Graphics.hpp>
#include <iostream>
#include "BoundedRectangle.h"
#include "FpsCounter.h"

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

class GameLogic {
private:
    sf::RenderWindow window;
    sf::VideoMode desktopMode;
    sf::Clock clock;
    BoundedRectangle boundedRectangle;
    FpsCounter fpsCounter;
    int screenWidth;
    int screenHeight;
    float width;
    float height;
    int fpsMax;
public:
    GameLogic(int screenWidthOrig, int screenHeightOrig, float widthOrig, float heightOrig, int fpsMaxOrig);
    ~GameLogic();
    void loop();
};

#endif // GAMELOGIC_H