#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../DEFS.h"


class Entity {
protected:
	sf::Texture entityTexture;
	sf::Sprite* entitySpirit;
	NumberOfXYParts spriteNumbers;
	float speed;
	sf::RenderWindow* window;
	MotionDirection lookingDirection;
	sf::Clock* Pclck;
	float swithcFrame, framCounter;
public:
	Entity(std::string texturePath, NumberOfXYParts& spriteNumbers, sf::RenderWindow* window, float speed, sf::Clock* Pclck);

	void SetSpeed(short&& speed);
	virtual void constraints() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	sf::Vector2f GetPostion();

	~Entity();
};
