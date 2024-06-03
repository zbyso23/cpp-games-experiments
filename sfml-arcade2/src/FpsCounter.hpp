#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

class FpsCounter {
private:
  sf::Clock fpsClock;
  int frameCount;
  float fps;
public:
  FpsCounter();
  ~FpsCounter();
  void addFrame();
};

#endif // FPSCOUNTER_H