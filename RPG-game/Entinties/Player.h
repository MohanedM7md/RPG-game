#pragma once
#include "Entity.h"
#define WIDTH 24
#define HEIGHT 32

class Player : public Entity {

private:
	short motionState;

public:
	Player(std::string texturePath, NumberOfXYParts&& spriteNumbers, sf::RenderWindow* window, sf::Clock* Pclck, float speed = 0);

	virtual void Update();
	virtual void constraints();
	virtual void Draw();

	~Player();

};