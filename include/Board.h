#pragma once
#include "File.h"
#include"Player.h"
#include "FiringMonster.h"
#include "StaticObject.h"
#include "Present.h"
#include <SFML/Graphics.hpp>
#include "Egg.h"
#include "Coin.h"
#include "RegularMonster.h"
#include "ScorePresent.h"
#include "TimePresent.h"
#include "LifePresent.h"


class Board
{
public:
	Board();
	void buildBoard();
	void setPositionScore(sf::Vector2f loc);
	void setPositionPlayer(Player&);
	void setPositionMonster(std::vector<std::unique_ptr<Monster>>& monsterVec,
		std::vector<std::unique_ptr<StaticObject>>& egg);
	void setTextureScoreBoard(sf::Texture*);
	sf::Sprite getSpriteScoreBoard ()const { return m_scoreBoard; }
	void setCoinPosition(std::vector<std::unique_ptr<StaticObject>>& coins);
	int getNumOfFiringMonster();
	void setPresentPosition(std::vector<std::unique_ptr<StaticObject>>& coins);
	void setLevel() { m_level++; }
	size_t getLevel()const { return m_level; }
	void delBoard() { m_boardGame.clear(); }
	void getFirstLevel() { m_level = 0; }
	//void getNumOfEggs();
	


private:
	std::vector <string> m_boardGame;
	File m_file;
	size_t m_level;
	sf::Sprite m_scoreBoard;
	int m_numCoins;
	

	 
};