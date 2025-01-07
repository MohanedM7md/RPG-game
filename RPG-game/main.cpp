#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFS.h"
#include <vector>
#include <cmath>
#include "Entinties/Player.h"
void closingWindow(sf::RenderWindow&);








int main()
{
    
    //! ######################### Create objects ############################
    sf::Texture monsterTexture;
    sf::Texture fireBallTexture;
    try {
        if (!monsterTexture.loadFromFile(".\\Assets\\Textures\\Monster\\Monster.png"))
            throw "Erorr Loading PLayer Texture";
        if(!fireBallTexture.loadFromFile(".\\Assets\\Textures\\Weabons\\fireball.png"))
            throw "Erorr Loading FireBall Texture";
    }
    catch (const char* err) {
        std::cout << err;
        return 0;
    }
   
    


    sf::Sprite monsterSpirit(monsterTexture);
    monsterSpirit.setTextureRect(sf::IntRect(sf::Vector2i(0 * 24, 4 * 32), sf::Vector2i(24, 32)));
    monsterSpirit.setScale(sf::Vector2f(3, 3));
    monsterSpirit.setPosition(sf::Vector2f(1000, 700));

    std::vector<sf::Sprite> fireballs;
    

    sf::RenderWindow window(sf::VideoMode({ 1240, 800 }), "RPG-Game!");
    Player player("..\\Assets\\Textures\\Player\\Fumiko.png", { 3,4 }, &window, 1);


    window.setFramerateLimit(60);
    short motionState = 0;
    while (window.isOpen())
    {

        //while (const std::optional event = window.pollEvent())
        //{
        //    std::cout << "is mouse and keybard now aren't event>?";
        //    if (const auto mouse = event->getIf<sf::Event::MouseButtonPressed>())
        //    {
        //       
        //        if (sf::Mouse::Button::Left == mouse->button)
        //        {
        //            std::cout << "yes Lef tMpuse pressed";
        //            sf::Sprite fireball(fireBallTexture,
        //                sf::IntRect(sf::Vector2i(0, 64 * 4), sf::Vector2i(64, 64)));
        //            fireball.setPosition(playerSpirit.getPosition());
        //            fireballs.push_back(fireball);
        //        }
        //        
        //    }
        //  

        //            

        //    // closingWindow(window);
        //}

        for (auto& fireball : fireballs) {
            sf::FloatRect boundingBox = fireball.getGlobalBounds();
            if (boundingBox.findIntersection(monsterSpirit.getGlobalBounds())) {
                fireballs.erase(fireballs.begin());
            }
            sf::Vector2f bulletDir = (monsterSpirit.getPosition() - fireball.getPosition());
            NormalizeVetor(bulletDir);
            
        }
        // ++++++++++++++++++++++++++++++ PLayer Movements +++++++++++++++++++++++++++++++  //
        
        
        player.Update();

        //! Checks if out of the screen
        

        window.clear(sf::Color::Cyan);
        player.Draw();
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


