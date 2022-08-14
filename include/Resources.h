#pragma once
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ScorePresent.h"
#include "LifePresent.h"
#include "TimePresent.h"
#include "Present.h"
#include <typeinfo>






using std::vector;

class Resources
{
public:
	Resources();

	sf::Texture* getPLAYERpic();
	sf::Texture* getFIRINGMONSTERpic();
	sf::Texture* getGAMECOINpic();
	sf::Texture* getPRESENTpic();
	sf::Texture* getOPENBACKGROUNDpic();
	sf::Texture* getGOLDENEGGpic();
	sf::Font* getCLOCKFont();
	sf::Texture* getFIRSTLEVELBACKGROUNDpic();
	sf::Texture* getSECONDLEVELBACKGROUNDpic();
	sf::Texture* getTHIRDLEVELpic();
	sf::Texture* getREGULARMONSTERpic();
	sf::Texture* getWINpic();
	sf::Texture* getGameBackground();
	sf::Texture* getGAMEOVERpic();
	sf::Texture* getScoreBoardpic();
	sf::Texture* getHELPpic();
	sf::SoundBuffer* getMusicGame();
	sf::Texture* getGATEpic();


	sf::Font* getFontScore();
	sf::Texture* getpresentpic(std::unique_ptr<StaticObject>&);

private:
	vector<sf::Texture> m_textureVec;
	sf::Font m_fonstOpenGme;
	sf::Font m_fontScoreBoard;
	sf::Font m_fontClock;
	sf::SoundBuffer m_music;
};