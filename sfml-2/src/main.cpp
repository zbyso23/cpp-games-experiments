#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    const float width = 100.0f;
    const float height = 100.0f;
    const int fpsMax = 60;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    window.setFramerateLimit(fpsMax);

    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(100.0f, 300.0f);

    float speed = 5000.0f; // pixels per second

    sf::Clock clock; // Create a clock object
    sf::Clock fpsClock;
    int frameCount = 0;
    float fps = 0.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Get the elapsed time since the last loop iteration
        float deltaTime = clock.restart().asSeconds();

        // Move the rectangle horizontally
        float offset = speed * deltaTime;
        float finalPosition = rectangle.getPosition().x + offset;
        if (finalPosition > window.getSize().x - width || finalPosition < 0) {
            finalPosition = speed > 0 ? window.getSize().x - width : 0;
            speed = -speed;
        }
        rectangle.setPosition(finalPosition, rectangle.getPosition().y);

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.display();

        // Update the frame count
        frameCount++;

        // Calculate FPS every second
        if (fpsClock.getElapsedTime().asSeconds() >= 1.0f) {
            fps = frameCount / fpsClock.getElapsedTime().asSeconds();
            frameCount = 0;
            fpsClock.restart();
            std::cout << "FPS: " << fps << std::endl;
        }
    }

    return 0;
}
