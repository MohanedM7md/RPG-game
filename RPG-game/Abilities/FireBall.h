#pragma once
#include "Ability.h"
#define WIDTH 64
#define HEIGHT 64
class FireBall : public Ability{
private:
	short motionState;

public:

	FireBall(sf::Vector2f playerPostion, std::string texturePath, NumberOfXYParts&& spriteNumbers, sf::RenderWindow* window, short speed = 0);
	FireBall(FireBall& fireball2);
	FireBall(FireBall&& fireball2);

	virtual void Update(const sf::Vector2f& Target);
	virtual void constraints();
	virtual void Draw();

	~FireBall();
};
