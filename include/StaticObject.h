#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include "Player.h"

class StaticObject:public Object
{
public:
	StaticObject() {};
	virtual void setTexture(sf::Texture*) = 0;
	virtual sf::Sprite getSprite()const = 0;
	virtual void setPosition(const sf::Vector2f&) = 0;
	virtual sf::Vector2f getPosition()const = 0;
	virtual int doAction(Player&) = 0;
	virtual bool isFalling()const = 0;
	virtual void falling(const sf::Vector2f& temp) = 0;

	

	


private:
	sf::Sprite m_photo;
};
