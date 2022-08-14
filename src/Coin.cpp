#pragma once
#include "Coin.h"

void Coin::setTexture(sf::Texture* tex)
{
	m_coinPhoto.setTexture(*tex);

}

void Coin::setPosition(const sf::Vector2f& pos)
{
	m_coinPhoto.setPosition(pos);
}

sf::Vector2f Coin::getPosition() const
{
	return m_coinPhoto.getPosition();
}

int Coin::doAction(Player& player)
{
	player.addScore(50);
	return(0);
}
