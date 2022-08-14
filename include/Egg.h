#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Player.h"





class Egg :public StaticObject
{
public:
	Egg() : m_fallingEgg(true) {};
	void setTexture(sf::Texture* tex);
	void falling(const sf::Vector2f& temp);
	void setPosition(const sf::Vector2f& );
	sf::Sprite getSprite()const;
	bool isFalling()const { return m_fallingEgg; }
	sf::Vector2f getPosition()const { return m_egg.getPosition(); }
	int doAction(Player&);
	void move();

	
private:
	sf::Sprite m_egg;
	sf::Clock m_eggClock;
	bool m_fallingEgg;

};