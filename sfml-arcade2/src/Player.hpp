#pragma once

#include "Sprite.hpp"

class Player : public Sprite {
public:
    Player(const std::string& textureFile, const sf::Vector2i& sheetSize, const std::string& executablePath);

private:
    std::vector<Frame> createIdleFrames(int offset);
    std::vector<Frame> createWalkFrames(int offset);
};
