#include "Player.h"



Player::Player(std::string texturePath, NumberOfXYParts&& spriteNumbers, sf::RenderWindow* window, short speed)
    :Entity(texturePath, spriteNumbers, window, speed), motionState(0)
{
    entitySpirit->setTextureRect(sf::IntRect(sf::Vector2i((motionState + WALKING) * WIDTH, lookingDirection * HEIGHT), sf::Vector2i(WIDTH, HEIGHT)));

}

void Player::Update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        entitySpirit->move(sf::Vector2f(-10 * speed, 0));
        lookingDirection = LEFT_NO_GUN;
        motionState = (motionState + 1) % 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        entitySpirit->move(sf::Vector2f(10 * speed, 0.0f));
        lookingDirection = RIGHT_NO_GUN;
        motionState = (motionState + 1) % 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        entitySpirit->move(sf::Vector2f(0.0f, 10 * speed));
        lookingDirection = DOWN_NO_GUN;
        motionState = (motionState + 1) % 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        entitySpirit->move(sf::Vector2f(0.0f, -10 * speed));
        lookingDirection = UP_NO_GUN;
        motionState = (motionState + 1) % 3;
    }
    entitySpirit->setTextureRect(sf::IntRect(sf::Vector2i((motionState + WALKING) * WIDTH, lookingDirection * HEIGHT), sf::Vector2i(WIDTH, HEIGHT)));
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
