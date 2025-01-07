#include "FireBall.h"



FireBall::FireBall(std::string texturePath, NumberOfXYParts&& spriteNumbers, sf::RenderWindow* window, short speed)
    :Ability(texturePath, spriteNumbers, window, speed), motionState(0)
{
    abilitySpirit->setTextureRect(sf::IntRect(sf::Vector2i((motionState + WALKING) * WIDTH, FiredDirection * HEIGHT), sf::Vector2i(WIDTH, HEIGHT)));

}

void FireBall::Update(const sf::Vector2f& Target)
{
    abilitySpirit->move(Target);
    sf::Vector2f fireBallPostion = abilitySpirit->getPosition();
    if()
    abilitySpirit->setTextureRect(sf::IntRect(sf::Vector2i((motionState + WALKING) * WIDTH, FiredDirection * HEIGHT), sf::Vector2i(WIDTH, HEIGHT)));
}

void FireBall::constraints()
{
    auto FireBallBounds = entitySpirit->getGlobalBounds();
    if (FireBallBounds.position.x < 0.f)
        entitySpirit->setPosition(sf::Vector2f(0, entitySpirit->getPosition().y));
    if (FireBallBounds.position.y < 0.f)
        entitySpirit->setPosition(sf::Vector2f(entitySpirit->getPosition().x, 0));
}

void FireBall::Draw()
{
    window->draw(*this->entitySpirit);
}

FireBall::~FireBall()
{
}
