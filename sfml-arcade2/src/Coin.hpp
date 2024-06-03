#ifndef COIN_HPP
#define COIN_HPP

#include "Sprite.hpp"

class Coin : public Sprite
{
public:
    Coin(const std::string& textureFile, const sf::Vector2i& frameSize, const std::string& executablePath);
};

#endif // COIN_HPP
