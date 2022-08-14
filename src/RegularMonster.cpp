#pragma once
#include "RegularMonster.h"



RegularMonster::RegularMonster(): m_rectMonster(0, 0, 81, 130)
{	
	m_photo.setScale(-1.2, 1.2);
}

void RegularMonster::setTexture(sf::Texture* tex)
{
	m_photo.setTexture(*tex);
}

void RegularMonster::setPositionSprite(const sf::Vector2f& pos)
{
	m_photo.setPosition(pos);
}


sf::Vector2f RegularMonster::getPosition()const
{
	return m_photo.getPosition();
}

void RegularMonster::locOfFrame( const bool& isRight)
{
	
	m_photo.setTextureRect(m_rectMonster);
}

void RegularMonster::setPosition(const sf::Vector2f& pos)
{
	m_photo.setPosition(pos);
}

void RegularMonster::move()
{
	sf::Vector2f loc;
	loc=m_photo.getPosition();
	
	if (m_photo.getPosition().x - 0.5f >= 20.f) 
		m_photo.setPosition(loc.x - 5.f, loc.y);

	else {
		sf::Vector2f temp = m_photo.getPosition();
		temp.x = 5870.f;
		m_photo.setPosition(temp);
	}
}

void RegularMonster:: moveFrame(const int& firstNum, const int& secondNum,
	 bool& isRight, sf::Time time)
{
	if (time.asMilliseconds() % 4 == 0) 
	{
		if (m_rectMonster.left == 400)
			m_rectMonster.left = 0;
		else
			m_rectMonster.left += 80;

		locOfFrame( isRight);
	}
}