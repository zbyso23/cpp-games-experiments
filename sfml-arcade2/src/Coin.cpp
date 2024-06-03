#include "Coin.hpp"

Coin::Coin(const std::string& textureFile, const sf::Vector2i& frameSize, const std::string& executablePath)
    : Sprite(textureFile, frameSize, executablePath)
{
    addAnimation("spin", {
        { 0, 0, false, {false, false} },
        { 0, 1, false, {false, false} },
        { 0, 2, false, {false, false} },
        { 0, 3, false, {false, false} }
    });

    setAnimation("spin");
}
