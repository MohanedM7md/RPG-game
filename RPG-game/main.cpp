#include <SFML/Graphics.hpp>
#include <iostream>

bool closingWindow(std::optional<sf::Event>, const sf::Window);


int main()
{
    sf::Texture playerTexture;
    try {
        if (!playerTexture.loadFromFile(".\\Assets\\Textures\\Player\\Fumiko.png"))
            throw "Erorr Loading Texture";
    }
    catch (const char* err) {
        std::cout << err;
    }

    sf::Sprite playerSpirit(playerTexture);

    playerSpirit.setTextureRect(sf::IntRect(sf::Vector2i(2 * 24, 2 * 32), sf::Vector2i(24, 32)));
    playerSpirit.setScale(sf::Vector2f(3, 3));
    sf::RenderWindow window(sf::VideoMode({ 1240, 800 }), "RPG-Game!");

    while (window.isOpen())
    {

        const auto onClose = [&window](const sf::Event::Closed&)
            {
                window.close();
            };
        const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
            {
                if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            };

        window.handleEvents(onClose, onKeyPressed);

        sf::Vector2f postion = playerSpirit.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            playerSpirit.setPosition(postion - sf::Vector2f(1, 0));
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            playerSpirit.setPosition(postion + sf::Vector2f(1, 0.0f));
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            playerSpirit.setPosition(postion + sf::Vector2f(0.0f, 1));
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            playerSpirit.setPosition(postion - sf::Vector2f(0.0f, 1));


        window.clear(sf::Color::Cyan);
        window.draw(playerSpirit);
        window.display();
    }
}

