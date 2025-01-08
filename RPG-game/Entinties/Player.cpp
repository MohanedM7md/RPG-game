#include "Player.h"
#include <iostream>


Player::Player(std::string texturePath, NumberOfXYParts&& spriteNumbers, sf::RenderWindow* window, sf::Clock* Pclck, float speed)
    :Entity(texturePath, spriteNumbers, window, speed, Pclck), motionState(0)
{
    entitySpirit->setTextureRect(sf::IntRect(sf::Vector2i((motionState + WALKING) * WIDTH, lookingDirection * HEIGHT), sf::Vector2i(WIDTH, HEIGHT)));

}

void Player::Update()
{
    sf::Time deltaTime = Pclck->restart();
    int newSpeed;
    framCounter +=newSpeed = deltaTime.asMilliseconds() * speed;
    bool isMoving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        entitySpirit->move(sf::Vector2f(-1 * newSpeed, 0));
        lookingDirection = LEFT_NO_GUN;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        entitySpirit->move(sf::Vector2f(1 * newSpeed, 0.0f));
        lookingDirection = RIGHT_NO_GUN;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        entitySpirit->move(sf::Vector2f(0.0f, 1 * newSpeed));
        lookingDirection = DOWN_NO_GUN;
        isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        entitySpirit->move(sf::Vector2f(0.0f, -1 * newSpeed));
        lookingDirection = UP_NO_GUN;
        isMoving = true;
    }
    if (isMoving) {
        entitySpirit->setTextureRect(sf::IntRect(sf::Vector2i((motionState + WALKING) * WIDTH, lookingDirection * HEIGHT), sf::Vector2i(WIDTH, HEIGHT)));
        std::cout << framCounter << "  ;  " << swithcFrame;
        if (framCounter >= swithcFrame) {
            motionState = (++motionState) % 3;
            framCounter = 0;
        }
    }
}

void Player::constraints()
{
    auto playerBounds = entitySpirit->getGlobalBounds();
    if (playerBounds.position.x < 0.f)
        entitySpirit->setPosition(sf::Vector2f(0, entitySpirit->getPosition().y));
    if (playerBounds.position.y < 0.f)
        entitySpirit->setPosition(sf::Vector2f(entitySpirit->getPosition().x, 0));
}

void Player::Draw()
{
	window->draw(*this->entitySpirit);
}

Player::~Player()
{
}
