#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

#include <vector>
enum direction { D_UP, D_DOWN, D_LEFT, D_RIGHT };


class Player :public MovingObject
{
public:
	Player():m_lives(3),m_score(0), m_rectSourceSprite(0, 0, 100, 92) { m_photo.setScale(1.2f, 1.2f); }
	Player(sf::Texture*);
	void setTexture(sf::Texture*);
	sf::Vector2f getPlayerPos() { return m_photo.getPosition(); }
	void lessLife() { m_lives--; }
	void addLife() {  m_lives += 1;}
	sf::Sprite getSprite()const { return m_photo; }
	int getLives() { return m_lives; }
	void move(int num);
	void locOfFrame(const bool&);
	sf::Vector2f getPosition() const;
	void setPosition(const sf::Vector2f&);
	void jumpPlayer(float x, float y);
	void moveF(sf::Vector2f t) { m_photo.move(t); };
	int getNumOfLives()const { return m_lives; }
	int getNumOfScore()const { return m_score; }
	void addScore(const int); 
	void setLives() { m_lives = 3; }
	sf::IntRect getSpriteSize()const { return m_rectSourceSprite; }
	void moveFrame(const int& firstNum, const int& secondNum,
	bool& isRight, sf::Time time) ;
	void setSpriteSize(const sf::IntRect&);
	void setFirsPosition(const sf::Vector2f& f) {
		m_firstPosition = f;}
	sf::Vector2f  getFirstPosition()const {return m_firstPosition;}
	
private:
	sf::Sprite m_photo;
	int m_lives;
	int m_score;
	sf::IntRect m_rectSourceSprite;
	sf::Vector2f m_firstPosition;

};