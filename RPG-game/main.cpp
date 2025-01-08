#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFS.h"
#include <vector>
#include <cmath>
#include "Entinties/Player.h"
#include "Abilities/FireBall.h"
void closingWindow(sf::RenderWindow&);








int main()
{
    
    //! ######################### Create objects ############################
    sf::Texture monsterTexture;
    
    try {
        if (!monsterTexture.loadFromFile(".\\Assets\\Textures\\Monster\\Monster.png"))
            throw "Erorr Loading PLayer Texture";
        
    }
    catch (const char* err) {
        std::cout << err;
        return 0;
    }
   
    


    sf::Sprite monsterSpirit(monsterTexture);
    monsterSpirit.setTextureRect(sf::IntRect(sf::Vector2i(0 * 24, 4 * 32), sf::Vector2i(24, 32)));
    monsterSpirit.setScale(sf::Vector2f(3, 3));
    monsterSpirit.setPosition(sf::Vector2f(1000, 700));


    

    sf::RenderWindow window(sf::VideoMode({ 1240, 800 }), "RPG-Game!");
    window.setFramerateLimit(60);
    sf::Clock * myclock = new sf::Clock();

    Player player("..\\Assets\\Textures\\Player\\Fumiko.png", { 3,4 }, &window, myclock,.4);
    std::vector<FireBall*> fireballs;

    while (window.isOpen())
    {

        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            fireballs.push_back(new FireBall(player.GetPostion(), "..\\Assets\\extures\\Weabons\\fireball.png", {3,4}, &window, 1));

        for (auto& fireball : fireballs)
            fireball->Update(monsterSpirit.getPosition());   
        
     
        player.Update();
        window.clear(sf::Color::Cyan);
        player.Draw();
        for (auto& fireball : fireballs) {
            fireball->Draw();
        }
        window.draw(monsterSpirit);
        window.display();
    }
    for (int i = 0; i < fireballs.size(); i++) {
        delete fireballs.at(0);
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


