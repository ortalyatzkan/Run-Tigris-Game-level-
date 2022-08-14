#pragma once
#include "Present.h"
#include <SFML/Graphics.hpp>

class LifePresent : public Present
{
public:
	LifePresent() {};
	void setTexture(sf::Texture*);
	void falling(const sf::Vector2f&) { ; }
	bool isFalling()const { return false; }
	sf::Sprite getSprite()const { return m_photo; }
	void setPosition(const sf::Vector2f&);
	sf::Vector2f getPosition()const;
	void move() {};
	int doAction(Player&);



	


private:
	sf::Sprite m_photo;
};