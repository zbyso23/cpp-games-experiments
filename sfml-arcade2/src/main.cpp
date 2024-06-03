#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Coin.hpp"
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
    // Player player("images/sprites-test-double.png", sf::Vector2i(184, 104), argv[0]);
    // Enemy enemy("enemy_sprites.png", sf::Vector2i(40, 40), argv[0]);
    // Coin coin("coin_sprites.png", sf::Vector2i(40, 40), argv[0]);

    player.setPosition(100, 100);
    // enemy.setPosition(300, 100);
    // coin.setPosition(500, 100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();
        // std::cout << "--- player.update()" << std::endl;
        player.update(dt);
        // enemy.update();
        // coin.update();

        // std::cout << "--- window.clear()" << std::endl;
        window.clear();
        
        // std::cout << "--- player.draw(window)" << std::endl;

        player.draw(window);
        // enemy.draw(window);
        // coin.draw(window);

        window.display();
    }

    return 0;
}

