#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Sprite.hpp"

class Enemy : public Sprite
{
public:
    Enemy(const std::string& textureFile, const sf::Vector2i& frameSize, const std::string& executablePath);
};

#endif // ENEMY_HPP
