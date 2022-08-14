#pragma once
#include "MovingObject.h"
#include <SFML/Graphics.hpp>


class Monster:public MovingObject
{
public:
	virtual sf::Sprite getSprite()const = 0;
	virtual sf::Vector2f getPosition()const = 0;
	virtual void move() = 0;
	virtual void setTexture(sf::Texture* tex) = 0;
	virtual void setPosition(const sf::Vector2f& pos) = 0;
	virtual void locOfFrame( const bool&) = 0;
	virtual void moveFrame( const int& firstNum, const int& secondNum,
								bool& isRight, sf::Time time)=0;
private:

};