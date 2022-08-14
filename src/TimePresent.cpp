#include "TimePresent.h"

void TimePresent::setPosition(const sf::Vector2f& pos)
{
	m_photo.setPosition(pos);
}

sf::Vector2f TimePresent::getPosition() const
{
	return m_photo.getPosition();
}

void TimePresent::setTexture(sf::Texture* texture)
{
	m_photo.setTexture(*texture);
}

int TimePresent::doAction(Player& p)
{
	return (30);
}