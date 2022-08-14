#include "ScorePresent.h"

void ScorePresent::setPosition(const sf::Vector2f& pos)
{
	m_photo.setPosition(pos);
}

sf::Vector2f ScorePresent::getPosition() const
{
	return m_photo.getPosition();
}

void ScorePresent::setTexture( sf::Texture* texture)
{
	m_photo.setTexture(*texture);
}

int ScorePresent::doAction(Player& p)
{
	p.addScore(100);
	return 0;
}
