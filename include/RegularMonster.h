#pragma once
#include "Monster.h"
#include <SFML/Graphics.hpp>


class RegularMonster:public Monster
{
public:
	RegularMonster();
	sf::Sprite getSprite()const { return m_photo; }
	sf::Vector2f getPosition()const;
	void move();
	void locOfFrame( const bool&);
	void setTexture(sf::Texture* tex);
	void setPositionSprite(const sf::Vector2f& pos);
	void setPosition(const sf::Vector2f& pos);
	sf::Clock getClock()const { return m_clock; }
	void setClock(sf::Clock clock) { m_clock = clock; }
	void moveFrame(const int& firstNum, const int& secondNum,
				bool& isRight, sf::Time time);



 private:
	sf::Sprite m_photo;
	sf::Clock m_clock;
	sf::IntRect m_rectMonster;
};