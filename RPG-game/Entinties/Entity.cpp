#include "Entity.h"

Entity::Entity(std::string texturePath, NumberOfXYParts& spriteNumbers,sf::RenderWindow* window,short speed)
	:window(window), spriteNumbers(spriteNumbers), lookingDirection(UP_NO_GUN),speed(speed)
{
		if (!entityTexture.loadFromFile(".\\Assets\\Textures\\Player\\Fumiko.png"))
			throw "Couldn't Load Entity texture";

		entitySpirit = new sf::Sprite(entityTexture);
		entitySpirit->setScale(sf::Vector2f(3, 3));
}

void Entity::SetSpeed(short&& speed)
{
	if (speed < 0)
		throw "Erorr Negative speed setting";

	this->speed = speed;
}

Entity::~Entity()
{
	delete entitySpirit;
}
