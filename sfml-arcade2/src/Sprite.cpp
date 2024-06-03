#include "Sprite.hpp"

Sprite::Sprite(const std::string& textureFile, const sf::Vector2i& sheetSize, const std::string& executablePath)
{
    // Get the directory of the executable
    std::string execDir = executablePath.substr(0, executablePath.find_last_of("/\\"));

    // Construct the full path to the texture file
    std::string textureFullPath = execDir + "/resources/" + textureFile;

    if (!texture.loadFromFile(textureFullPath))
    {
        throw std::runtime_error("Failed to load texture: " + textureFullPath);
    }

    int width = sheetSize.x * 32;
    int height = sheetSize.y * 32;
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));

    sprite.setTexture(texture);
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

        if (isPingPong && (currentFrame == 0 || currentFrame == animations[currentAnimation].size() - 1))
            reverseDirection = !reverseDirection;

        if (reverseDirection)
            currentFrame--;
        else
            currentFrame++;

        if (currentFrame < 0 || currentFrame >= animations[currentAnimation].size()) {
            if (isLooping)
                currentFrame = reverseDirection ? animations[currentAnimation].size() - 1 : 0;
            else
                currentFrame = std::max(0, std::min(static_cast<int>(animations[currentAnimation].size()) - 1, currentFrame));
        }

        const Frame& frame = animations[currentAnimation][currentFrame];
        sf::IntRect rect(frame.col * 32, frame.row * 32, 32, 32);
        if (frame.doubleWidth)
            rect.width *= 2;
        if (frame.doubleHeight)
            rect.height *= 2;
        sprite.setTextureRect(rect);
        sprite.setScale(frame.flipped ? -1.0f : 1.0f, 1.0f);
    }
}

void Sprite::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
