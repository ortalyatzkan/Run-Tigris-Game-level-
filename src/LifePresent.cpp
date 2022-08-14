#include "LifePresent.h"

void LifePresent::setPosition(const sf::Vector2f& pos)
{
	m_photo.setPosition(pos);
}

sf::Vector2f LifePresent::getPosition() const
{
	return m_photo.getPosition();
}

void LifePresent::setTexture(sf::Texture* texture)
{
	m_photo.setTexture(*texture);
}

int LifePresent::doAction(Player& p)
{
	p.addLife();
	return 0;
}
