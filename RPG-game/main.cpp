#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
void closingWindow(sf::RenderWindow&);


void NormalizeVetor(sf::Vector2f&);

int main()
{

    //! ######################### Create objects ############################
    sf::Texture playerTexture;
    sf::Texture monsterTexture;
    sf::Texture fireBallTexture;
    try {
        if (!playerTexture.loadFromFile(".\\Assets\\Textures\\Player\\Fumiko.png"))
            throw "Erorr Loading PLayer Texture";
        if (!monsterTexture.loadFromFile(".\\Assets\\Textures\\Monster\\Monster.png"))
            throw "Erorr Loading PLayer Texture";
        if(!fireBallTexture.loadFromFile(".\\Assets\\Textures\\Weabons\\fireball.png"))
            throw "Erorr Loading FireBall Texture";
    }
    catch (const char* err) {
        std::cout << err;
        return 0;
    }

    sf::Sprite playerSpirit(playerTexture);
    playerSpirit.setTextureRect(sf::IntRect(sf::Vector2i(2 * 24, 2 * 32), sf::Vector2i(24, 32)));
    playerSpirit.setScale(sf::Vector2f(3, 3));


    sf::Sprite monsterSpirit(monsterTexture);
    monsterSpirit.setTextureRect(sf::IntRect(sf::Vector2i(0 * 24, 4 * 32), sf::Vector2i(24, 32)));
    monsterSpirit.setScale(sf::Vector2f(3, 3));
    monsterSpirit.setPosition(sf::Vector2f(1000, 700));

    std::vector<sf::Sprite> fireballs;


    sf::RenderWindow window(sf::VideoMode({ 1240, 800 }), "RPG-Game!");
    
    while (window.isOpen())
    {


        while (const std::optional event = window.pollEvent())
        {
            std::cout << "is mouse and keybard now aren't event>?";
            if (const auto mouse = event->getIf<sf::Event::MouseButtonPressed>())
            {
                std::cout << "yes Mpuse pressed";
                if (sf::Mouse::Button::Left == mouse->button)
                {
                    std::cout << "yes Lef tMpuse pressed";
                    sf::Sprite fireball(fireBallTexture,
                        sf::IntRect(sf::Vector2i(0, 64 * 4), sf::Vector2i(64, 64)));
                    fireball.setPosition(playerSpirit.getPosition());
                    fireballs.push_back(fireball);
                }
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::X)
                    std::cout << "X pressed";
            }

       // closingWindow(window);
        }
        

        for (auto& fireball : fireballs) {
            sf::Vector2f bulletDir = (monsterSpirit.getPosition() - fireball.getPosition());
            NormalizeVetor(bulletDir);
            fireball.setPosition(fireball.getPosition() + bulletDir);
        }

        sf::Vector2f Playerpostion = playerSpirit.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            playerSpirit.setPosition(Playerpostion - sf::Vector2f(.1f, 0));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            playerSpirit.setPosition(Playerpostion + sf::Vector2f(.1f, 0.0f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            playerSpirit.setPosition(Playerpostion + sf::Vector2f(0.0f, .1f));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            playerSpirit.setPosition(Playerpostion - sf::Vector2f(0.0f, .1f));


        window.clear(sf::Color::Cyan);
        window.draw(playerSpirit);
        for (auto &fireball : fireballs)
            window.draw(fireball);
        window.draw(monsterSpirit);
        window.display();
    }
}

void closingWindow(sf::RenderWindow& window)
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
}

void NormalizeVetor(sf::Vector2f& vec)
{
    float Mag = sqrt(vec.x * vec.x + vec.y * vec.y);
    vec.x /= Mag;
    vec.y /= Mag;
}
