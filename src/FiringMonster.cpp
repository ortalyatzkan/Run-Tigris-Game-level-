#pragma once
#include "FiringMonster.h"

FiringMonster::FiringMonster():m_firstTime(true),m_rightSide(true), m_rectMonster(0, 0, 106, 130)
{
}

void FiringMonster::setTexture(sf::Texture* tex)
{
	m_photo.setTexture(*tex);
}



void FiringMonster::setPositionSprite(const sf::Vector2f& pos)
{
	m_photo.setPosition(pos);
}

sf::Vector2f FiringMonster::getPosition()const
{
	return m_photo.getPosition();
}

void FiringMonster::locOfFrame( const bool& isRight)
{
	m_photo.setTextureRect(m_rectMonster);
}

void FiringMonster::setPosition(const sf::Vector2f& pos)
{
	m_photo.setPosition(pos);
}

void FiringMonster::move()
{
	sf::Vector2f loc;
	loc = m_photo.getPosition();

	if (m_photo.getPosition().x + 0.5f >= 5870.f && m_rightSide) {
		m_photo.setPosition(loc.x - 5.f, loc.y);
		m_rightSide = false;
		m_photo.setScale(-1.2f, 1.2f);
	}

	else if (m_photo.getPosition().x - 0.5f <= 120.f && !m_rightSide) {
		m_photo.setPosition(loc.x + 5.f, loc.y);
		m_rightSide = true;
		m_photo.setScale(1.2f, 1.2f);
	}

	else if (m_rightSide)
		m_photo.setPosition(loc.x + 5.f, loc.y);

	else
		m_photo.setPosition(loc.x - 5.f, loc.y);

}

void FiringMonster:: moveFrame(const int& firstNum, const int& secondNum,
	 bool& isRight, sf::Time time)
{
	if (time.asMilliseconds() % 4 == 0) {
		if (m_rectMonster.left == firstNum)
			m_rectMonster.left = 0;
		else
			m_rectMonster.left += secondNum;

		locOfFrame( isRight);
	}
}

