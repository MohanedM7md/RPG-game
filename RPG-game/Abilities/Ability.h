#pragma once
#include <SFML/Graphics.hpp>
#include "../DEFS.h"

class Ability {

protected:
	sf::Texture abilityTexture;
	sf::Sprite* abilitySpirit;
	NumberOfXYParts spriteNumbers;
	short speed;
	sf::RenderWindow* window;
	ProjectileDirection FiredDirection;
	std::string texturePath;
	sf::Vector2f playerPostion;
	size_t FireRat;

public:
	Ability(sf::Vector2f playerPostion,std::string texturePath, NumberOfXYParts& spriteNumbers, sf::RenderWindow* window, short speed = 0, size_t FireRat = 1000);

	void SetSpeed(short&& speed);
	virtual void constraints() = 0;
	virtual void Update(const sf::Vector2f& Target) = 0;
	virtual void Draw() = 0;
	size_t getFireRate() const;
};
