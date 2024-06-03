#include "Player.hpp"

Player::Player(const std::string& textureFile, const sf::Vector2i& sheetSize, const std::string& executablePath) : 
    Sprite(textureFile, sheetSize, executablePath) {

    // Create idle animation frames
    std::vector<Frame> idleFrames = createIdleFrames(0);
    addAnimation("idle", idleFrames);

    // Create walk animation frames
    // std::vector<Frame> walkFrames = createWalkFrames(3);
    // addAnimation("walk", walkFrames);

    // Set initial animation
    setAnimation("idle", 0.6f, true, false);
}

std::vector<Frame> Player::createIdleFrames(int offset) {
    std::vector<Frame> frames;
    // Define idle frames with double width and height
    for (int i = 0; i < 3; ++i) {
        Frame frame;
        frame.row = 0;
        frame.col = i + offset;
        frame.flipped = false;
        frames.push_back(frame);
    }
    return frames;
}

std::vector<Frame> Player::createWalkFrames(int offset) {
    std::vector<Frame> frames;
    // Define walk frames with double width and height
    for (int i = 0; i < 3; ++i) {
        Frame frame;
        frame.row = 1;
        frame.col = i + offset;
        frame.flipped = false;
        frames.push_back(frame);
    }
    return frames;
}
