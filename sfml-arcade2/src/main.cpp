#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "FpsCounter.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 1)
    {
        std::cerr << "Error: Unable to get the executable path." << std::endl;
        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "River Raid");
    sf::Clock clock;

    Player player("images/sprites-test-combined.png", sf::Vector2i(92, 104), argv[0]);
    FpsCounter fpsCounter;
    player.setPosition(100, 100);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();
        // std::cout << "Dt: [" << dt << "]" << std::endl;
        player.update(dt);

        window.clear();
        
        player.draw(window);
        window.display();
        fpsCounter.addFrame();

    }

    return 0;
}

