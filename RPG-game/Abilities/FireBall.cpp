#include "FireBall.h"


void NormalizeVetor(sf::Vector2f& vec)
{
    float Mag = sqrt(vec.x * vec.x + vec.y * vec.y);
    vec.x /= Mag;
    vec.y /= Mag;
}


FireBall::FireBall(sf::Vector2f playerPostion,std::string texturePath, NumberOfXYParts&& spriteNumbers, sf::RenderWindow* window, short speed)
    :Ability(playerPostion,texturePath, spriteNumbers, window, speed), motionState(0)
{
    abilitySpirit->setTextureRect(sf::IntRect(sf::Vector2i((motionState + WALKING) * WIDTH, FiredDirection * HEIGHT), sf::Vector2i(WIDTH, HEIGHT)));

}

FireBall::FireBall(FireBall& fireball2) :Ability(fireball2.playerPostion, fireball2.texturePath, fireball2.spriteNumbers, fireball2.window, fireball2.speed), motionState(0)
{
    abilitySpirit->setTextureRect(sf::IntRect(sf::Vector2i((motionState + WALKING) * WIDTH, FiredDirection * HEIGHT), sf::Vector2i(WIDTH, HEIGHT)));
}

FireBall::FireBall(FireBall&& fireball2) :Ability(fireball2.playerPostion,fireball2.texturePath, fireball2.spriteNumbers, fireball2.window, fireball2.speed), motionState(0)
{
    abilitySpirit->setTextureRect(sf::IntRect(sf::Vector2i((motionState + WALKING) * WIDTH, FiredDirection * HEIGHT), sf::Vector2i(WIDTH, HEIGHT)));
}

void FireBall::Update(const sf::Vector2f& Target)
{
    
    sf::Vector2f normalizedDir = (Target - abilitySpirit->getPosition()).normalized();
        

        sf::Vector2f fireBallPostion = abilitySpirit->getPosition();
        if (fireBallPostion.x < Target.x) {
            FiredDirection = RIGHT;
            if (fireBallPostion.y < Target.y)
                FiredDirection = RIGHT_DOWN;
            else if (fireBallPostion.y > Target.y)
                FiredDirection = RIGHT_UP;
        }
        else if (fireBallPostion.x > Target.x) {
            FiredDirection = LEFT;
            if (fireBallPostion.y < Target.y)
                FiredDirection = LEFT_DOWN;
            else if (fireBallPostion.y > Target.y)
                FiredDirection = LEFT_UP;
        }
        else if (fireBallPostion.x = Target.x) {
            if (fireBallPostion.y < Target.y)
                FiredDirection = DOWN;
            else if (fireBallPostion.y > Target.y)
                FiredDirection = UP;
        }
        abilitySpirit->move(normalizedDir);
        abilitySpirit->setTextureRect(sf::IntRect(sf::Vector2i((motionState + WALKING) * WIDTH, FiredDirection * HEIGHT), sf::Vector2i(WIDTH, HEIGHT)));
        motionState = (motionState + 1) % 8;
    
}

void FireBall::constraints()
{
   
}

void FireBall::Draw()
{
    window->draw(*this->abilitySpirit);
}

FireBall::~FireBall()
{
}
