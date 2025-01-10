#include "Ability.h"

Ability::Ability(sf::Vector2f playerPostion,std::string texturePath, NumberOfXYParts& spriteNumbers, sf::RenderWindow* window, short speed,size_t FireRat )
	:window(window), spriteNumbers(spriteNumbers), FiredDirection(RIGHT), speed(speed),texturePath(texturePath), playerPostion(playerPostion), FireRat(FireRat)
{
	if (!abilityTexture.loadFromFile(".\\Assets\\Textures\\Weabons\\fireball.png"))
		throw "Couldn't Load Entity texture";

	abilitySpirit = new sf::Sprite(abilityTexture);
	abilitySpirit->setPosition(playerPostion);
	abilitySpirit->setScale(sf::Vector2f(3, 3));
}

size_t Ability::getFireRate() const
{
	return 0;
}

