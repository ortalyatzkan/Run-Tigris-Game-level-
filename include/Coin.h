#pragma once
#include "StaticObject.h"
#include "Player.h"

class Coin:public StaticObject
{
public:
	Coin() {};
	void setTexture(sf::Texture* tex);
	void falling(const sf::Vector2f&) {;}
	bool isFalling()const { return false; }
	sf::Sprite getSprite()const { return m_coinPhoto; }
	void setPosition(const sf::Vector2f&);
	sf::Vector2f getPosition()const;
	void move() {};
	int doAction(Player&) ;



private:
	sf::Sprite m_coinPhoto;
};