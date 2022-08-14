#include "Egg.h"


void Egg::setTexture(sf::Texture* tex)
{
	m_egg.setTexture(*tex);
}

void Egg::falling(const sf::Vector2f& temp)
{

	if (m_eggClock.getElapsedTime().asSeconds() > 3)
	{
		if (m_egg.getPosition().y < 580)
		{
			sf::Vector2f loc;
			loc = m_egg.getPosition();
			loc.y += 5.f;
			m_egg.setPosition(loc);
			m_fallingEgg = true;
		}

		else if (m_egg.getPosition().y >= 580)
		{
			m_eggClock.restart();
			m_egg.move(temp);
			setPosition(temp);
			m_fallingEgg = false;
		}
	}
	else {
		
		sf::Vector2f t ( temp.x,temp.y);
		t.y += 20;
		m_egg.setPosition(temp);
		m_fallingEgg = false;
	}
}

void Egg::setPosition(const sf::Vector2f& pos)
{
	m_egg.setPosition(pos);
}

sf::Sprite Egg::getSprite()const
{
	return m_egg;
}

int Egg::doAction(Player& player)
{
	player.lessLife();
	return(0);
}

void Egg::move()
{
	sf::Vector2f temp = m_egg.getPosition();
	temp.y += 10;
	m_egg.move(temp);
}