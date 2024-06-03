#include "Enemy.hpp"

Enemy::Enemy(const std::string& textureFile, const sf::Vector2i& frameSize, const std::string& executablePath)
    : Sprite(textureFile, frameSize, executablePath)
{
    addAnimation("fly", {
        { 0, 0, false, {false, false} },
        { 0, 1, false, {false, false} },
        { 0, 2, false, {false, false} }
    });

    setAnimation("fly");
}
