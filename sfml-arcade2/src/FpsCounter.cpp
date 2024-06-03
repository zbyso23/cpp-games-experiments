#include <iostream>
#include "FpsCounter.hpp"

FpsCounter::FpsCounter() :
frameCount(0),
fps(0.0f),
fpsClock(sf::Clock())
{
}

FpsCounter::~FpsCounter() {
}

void FpsCounter::addFrame() {
  frameCount++;
  if (fpsClock.getElapsedTime().asSeconds() < 1.0f) return;
  fps = frameCount / fpsClock.getElapsedTime().asSeconds();
  frameCount = 0;
  fpsClock.restart();
  std::cout << "FPS: " << fps << std::endl;
}