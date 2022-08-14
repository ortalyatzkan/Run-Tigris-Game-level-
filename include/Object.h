#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
	virtual sf::Sprite getSprite()const = 0;
	virtual sf::Vector2f getPosition()const = 0;
	virtual void setTexture(sf::Texture* tex) = 0;
	virtual void setPosition(const sf::Vector2f& pos) = 0;

private:

};