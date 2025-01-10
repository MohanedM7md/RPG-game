#include "Entity.h"

Entity::Entity(std::string texturePath, NumberOfXYParts& spriteNumbers,sf::RenderWindow* window, float speed, sf::Clock* Pclck)
	:window(window), spriteNumbers(spriteNumbers), lookingDirection(UP_NO_GUN),speed(speed), Pclck(Pclck), Mt(WALKING)
{
		if (!entityTexture.loadFromFile(".\\Assets\\Textures\\Player\\Fumiko.png"))
			throw "Couldn't Load Entity texture";
		swithcFrame = 60;
		framCounter = 0;
		entitySpirit = new sf::Sprite(entityTexture);
		entitySpirit->setScale(sf::Vector2f(3, 3));
}

void Entity::SetSpeed(short&& speed)
{
	if (speed < 0)
		throw "Erorr Negative speed setting";

	this->speed = speed;
}

sf::Vector2f Entity::GetPostion()
{
	return entitySpirit->getPosition();
}

Entity::~Entity()
{
	delete entitySpirit;
}
