#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Player.h"
#include "FiringMonster.h"
#include "Board.h"
#include"StaticObject.h"
#include "Present.h"
#include <SFML/Audio.hpp>
#include <typeinfo>


class Controller
{
public:
	bool run(bool&);
	void drawBoard(sf::View view, sf::Sprite photo, bool isRight, sf::Time&,sf::Sprite);
	void createText(sf::Time, const int);
	void collisionMonsterPlayer(const bool);
	void collisionCoin(const bool isRight, int& TimeClock);
	void printTime(sf::Time, const int);
	void buildBoard();
	void restart();
	void resetLevels();
	size_t getLevel() { return m_gameBoard.getLevel(); }
	sf::Texture* getMenu();
	sf::Texture* getGameOver();
	sf::Texture* getWinPic();
	sf::Texture* getHELPpic();
	void getPhotoLevel(sf::Sprite&);


private:
	sf::RenderWindow m_window;
	Resources m_resource;
	sf::Clock m_clock;
	Player m_player;
	Board m_gameBoard;
	std::vector<std::unique_ptr<Monster>> m_vecMonster;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
	int m_numOfFiringMonster;
	int m_timeGame;
	sf::Sound m_gameMusic;
	sf::Text m_textScore;
	sf::Text m_textLives;
	sf::Text m_time;
};
 
