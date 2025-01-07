#include "Ability.h"

Ability::Ability(std::string texturePath, NumberOfXYParts& spriteNumbers, sf::RenderWindow* window, short speed)
	:window(window), spriteNumbers(spriteNumbers), FiredDirection(RIGHT), speed(speed)
{
	if (!abilityTexture.loadFromFile(".\\Assets\\Textures\\Monster\\Monster.png"))
		throw "Couldn't Load Entity texture";

	abilitySpirit = new sf::Sprite(abilityTexture);
	abilitySpirit->setScale(sf::Vector2f(3, 3));
}

