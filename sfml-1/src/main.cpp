#include <SFML/Graphics.hpp>

int main() {
    // Create a window with the title "SFML Window"
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw your objects here

        // Display the window contents
        window.display();
    }

    return 0;
}

