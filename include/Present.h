#pragma once
#include "StaticObject.h"
#include "Player.h"

class Present: public StaticObject
{
public:
	virtual void setTexture(sf::Texture* tex)=0;
	virtual void falling(const sf::Vector2f&) = 0;
	virtual bool isFalling()const = 0;
	virtual sf::Sprite getSprite()const = 0;
	virtual void setPosition(const sf::Vector2f&)=0;
	virtual sf::Vector2f getPosition()const=0;
	virtual void move() =0;
	virtual int doAction(Player&)=0;


	
	


private:
};