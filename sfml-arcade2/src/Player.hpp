#pragma once

#include "Sprite.hpp"

class Player : public Sprite {
public:
    Player();

private:
    std::vector<Frame> createIdleFrames(int offset);
    std::vector<Frame> createWalkFrames(int offset);
};
