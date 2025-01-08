#include "Ability.h"

Ability::Ability(sf::Vector2f playerPostion,std::string texturePath, NumberOfXYParts& spriteNumbers, sf::RenderWindow* window, short speed)
	:window(window), spriteNumbers(spriteNumbers), FiredDirection(RIGHT), speed(speed),texturePath(texturePath), playerPostion(playerPostion)
{
	if (!abilityTexture.loadFromFile(".\\Assets\\Textures\\Weabons\\fireball.png"))
		throw "Couldn't Load Entity texture";

	abilitySpirit = new sf::Sprite(abilityTexture);
	abilitySpirit->setPosition(playerPostion);
	abilitySpirit->setScale(sf::Vector2f(3, 3));
}

