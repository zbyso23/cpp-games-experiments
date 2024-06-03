#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

struct Frame {
    int row;
    int col;
    bool flipped;
    bool doubleWidth;
    bool doubleHeight;
};

struct AnimationOffsets {
    std::vector<sf::Vector2i> offsets;
};

class Sprite {
public:
    Sprite(const std::string& filePath, const sf::Vector2i& sheetSize, const std::string& executablePath);

    void loadTexture(const std::string& filename);
    void addAnimation(const std::string& name, const std::vector<Frame>& frames);
    void setAnimation(const std::string& name, float speed, bool loop, bool pingPong);
    void setPosition(float x, float y);
    void update(float dt);
    void draw(sf::RenderWindow& window);
protected:
    sf::Vector2u textureSize;
    sf::Vector2i cellSize;
    bool prepared = false;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    std::unordered_map<std::string, std::vector<Frame>> animations;
    std::string currentAnimation;
    float animationSpeed;
    bool isLooping;
    bool isPingPong;
    bool reverseDirection = false;
    int currentFrame = 0;
    float elapsedTime = 0.0f;
};
