#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../DEFS.h"


class Entity {
protected:
	sf::Texture entityTexture;
	sf::Sprite* entitySpirit;
	NumberOfXYParts spriteNumbers;
	short speed;
	sf::RenderWindow* window;
	MotionDirection lookingDirection;

public:
	Entity(std::string texturePath, NumberOfXYParts & spriteNumbers, sf::RenderWindow* window, short speed = 0);
	
	void SetSpeed(short&& speed);
	virtual void constraints() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	~Entity();
};
