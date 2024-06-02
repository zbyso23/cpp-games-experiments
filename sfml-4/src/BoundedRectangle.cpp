#include <iostream>
#include "BoundedRectangle.h"

BoundedRectangle::BoundedRectangle(int screenWidthOrig, int screenHeightOrig, float widthOrig, float heightOrig, float speedOrig) :
  screenWidth(screenWidthOrig), 
  screenHeight(screenHeightOrig), 
  width(widthOrig), 
  height(heightOrig), 
  x(100.0f), 
  y(300.0f), 
  rectangle(sf::Vector2f(widthOrig, heightOrig)), 
  speed(speedOrig)
{
  rectangle.setFillColor(sf::Color::Green);
  rectangle.setPosition(x, y);
}

BoundedRectangle::~BoundedRectangle()
{
}

void BoundedRectangle::tick(float deltaTime)
{
  float offset = speed * deltaTime;
  float finalPosition = rectangle.getPosition().x + offset;
  if (finalPosition > screenWidth - width || finalPosition < 0) {
      finalPosition = speed > 0 ? screenWidth - width : 0;
      speed = -speed;
  }
  rectangle.setPosition(finalPosition, rectangle.getPosition().y);
}

const sf::RectangleShape& BoundedRectangle::get() const
{
  return rectangle;
}