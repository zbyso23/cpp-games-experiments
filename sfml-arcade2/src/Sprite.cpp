#include <iostream>
#include "Sprite.hpp"

Sprite::Sprite(const std::string& textureFile, const sf::Vector2i& sheetSize, const std::string& executablePath)
{
    std::string execDir = executablePath.substr(0, executablePath.find_last_of("/\\"));
    std::string textureFullPath = execDir + "/resources/" + textureFile;
    if (!texture.loadFromFile(textureFullPath))
    {
        throw std::runtime_error("Failed to load texture: " + textureFullPath);
    }
    textureSize = texture.getSize();
    cellSize = sheetSize;
    std::cout << "WxH: [" << textureSize.x << ", " << textureSize.y << "]" << std::endl;
    sprite.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
    sprite.setTexture(texture);
    std::cout << "WxH2: [" << cellSize.x << ", " << cellSize.y << "]" << std::endl;
}


void Sprite::addAnimation(const std::string& name, const std::vector<Frame>& frames) {
    animations[name] = frames;
}

void Sprite::setAnimation(const std::string& name, float speed, bool loop, bool pingPong) {
    currentAnimation = name;
    animationSpeed = speed;
    isLooping = loop;
    isPingPong = pingPong;
    currentFrame = 0;
    elapsedTime = 0.0f;
}

void Sprite::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Sprite::update(float dt) {
    if (currentAnimation.empty() || animations.find(currentAnimation) == animations.end())
        return;

    elapsedTime += dt;

    if (elapsedTime >= animationSpeed) {
        elapsedTime -= animationSpeed;

        // Reverse direction if we reach the start or end of the animation
        if (isPingPong && ((reverseDirection && currentFrame == 0) || (!reverseDirection && currentFrame == animations[currentAnimation].size() - 1))) {
            reverseDirection = !reverseDirection;
        }

        // Update the current frame index
        if (reverseDirection)
            currentFrame--;
        else
            currentFrame++;

        // Handle frame wrapping
        if (currentFrame < 0) {
            if (isLooping) {
                currentFrame = 1; // Set to the second frame to avoid repeating the first frame
                reverseDirection = false;
            } else {
                currentFrame = 0;
            }
        } else if (currentFrame >= animations[currentAnimation].size()) {
            if (isLooping) {
                currentFrame = animations[currentAnimation].size() - 2; // Set to the second-to-last frame to avoid repeating the last frame
                reverseDirection = true;
            } else {
                currentFrame = animations[currentAnimation].size() - 1;
            }
        }

        // Retrieve the current frame
        const Frame& frame = animations[currentAnimation][currentFrame];

        // Debug output for the current frame
        // std::cout << "Row x Cell: [" << frame.col << ", " << frame.row << "]" << std::endl;

        // Set the texture rectangle for the sprite
        sf::IntRect rect(frame.col * cellSize.x, frame.row * cellSize.y, cellSize.x, cellSize.y);
        sprite.setTextureRect(rect);

        // Set the scale of the sprite (for flipping)
        sprite.setScale(frame.flipped ? -1.0f : 1.0f, 1.0f);

        // Set the prepared flag if it's not already set
        if (!prepared) prepared = true;
    }
}


void Sprite::draw(sf::RenderWindow& window) {
    if (!prepared) return;
    window.draw(sprite);
}
