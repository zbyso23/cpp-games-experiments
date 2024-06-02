#include <iostream>
#include "FpsCounter.h"
#include "GameLogic.h"
#include "BoundedRectangle.h"

GameLogic::GameLogic(int screenWidthOrig, int screenHeightOrig, float widthOrig, float heightOrig, int fpsMaxOrig) : 
  screenWidth(screenWidthOrig),
  screenHeight(screenHeightOrig),
  desktopMode(sf::VideoMode::getDesktopMode()),
  window(desktopMode, "SFML Fullscreen", sf::Style::Fullscreen),
  fpsMax(fpsMaxOrig),
  boundedRectangle(screenWidthOrig, screenHeightOrig, widthOrig, heightOrig, 50.0f),
  fpsCounter()
{
  window.setFramerateLimit(fpsMax);
}

GameLogic::~GameLogic() {
}

void GameLogic::loop() {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    float deltaTime = clock.restart().asSeconds();
    boundedRectangle.tick(deltaTime);
    window.clear(sf::Color::Black);
    window.draw(boundedRectangle.get());
    window.display();
    fpsCounter.addFrame();
  }
}