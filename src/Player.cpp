#include "Player.h"

const int NUM_OF_LIVES = 3;

Player::Player(sf::Texture* texture):m_lives(NUM_OF_LIVES), m_score(0), m_rectSourceSprite(0, 0, 100, 92)
{

	setTexture(texture);
	m_photo.setScale(1.2f, 1.2f);
	
}

void Player::setTexture(sf::Texture* texture)
{
	m_photo.setTexture(*texture);
}

void Player::move(int num)
{
	sf::Vector2f temp = m_photo.getPosition();
	switch (num)
	{
	case(D_RIGHT):
		m_photo.setPosition(temp.x + 10, temp.y);
		break;

	case(D_LEFT):
		if (m_photo.getPosition().x != 0)
		m_photo.setPosition(temp.x -10, temp.y);
	
	}
}

void Player::locOfFrame(const bool &isRight)
{
	if(isRight==true)
		m_photo.setScale(1.2f, 1.2f);
	else
		m_photo.setScale(-1.2f, 1.2f);

	m_photo.setTextureRect(m_rectSourceSprite);
}

void Player:: setPosition(const sf::Vector2f& pos)
{
	m_photo.setScale(1.2f, 1.2f);
	m_photo.setPosition(pos);
}

sf::Vector2f Player:: getPosition() const
{
	return m_photo.getPosition();
}

void Player::jumpPlayer(float x, float y)
{
	m_photo.move(x, y);
}

void Player::addScore(const int num)
{
	m_score += num;
}
void Player:: moveFrame(const int& firstNum, const int& secondNum,
	 bool& isRight, sf::Time time)
{
	if (time.asMilliseconds() % 4 == 0) {
		if (m_rectSourceSprite.left == firstNum)
			m_rectSourceSprite.left = 0;
		else
			m_rectSourceSprite.left += secondNum;

		locOfFrame( isRight);
	}
}

void Player::setSpriteSize(const sf::IntRect& t)
{
	m_rectSourceSprite=t;
}
