#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef BOUNDEDRECTANGLE_H
#define BOUNDEDRECTANGLE_H

class BoundedRectangle {
private:
    sf::RectangleShape rectangle;
    int screenWidth;
    int screenHeight;
    float width;
    float height;
    float x;
    float y;
    float speed;
public:
    BoundedRectangle(int screenWidthOrig, int screenHeightOrig, float widthOrig, float heightOrig, float speed);
    ~BoundedRectangle();
    void tick(float deltaTime);
    const sf::RectangleShape& get() const;
};

#endif // BOUNDEDRECTANGLE_H