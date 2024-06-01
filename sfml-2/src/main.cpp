#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    sf::RectangleShape rectangle(sf::Vector2f(100.0f, 50.0f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(100.0f, 300.0f);

    float speed = 100.0f; // pixels per second

    sf::Clock clock; // Create a clock object

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Get the elapsed time since the last loop iteration
        float deltaTime = clock.restart().asSeconds();

        // Move the rectangle horizontally
        rectangle.move(speed * deltaTime, 0.0f);

        // Reverse direction when reaching window boundaries
        if (rectangle.getPosition().x + rectangle.getSize().x > window.getSize().x ||
            rectangle.getPosition().x < 0) {
            speed = -speed; // Reverse direction
        }

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
