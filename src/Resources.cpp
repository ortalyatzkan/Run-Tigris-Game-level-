#pragma once
#include "Resources.h"
#include <thread>

const int NUM_OF_PICTURES = 19;

enum namePic { P_PLAYER, P_REGULARMONSTER, P_FIRINGMONSTER, P_PRESENT, P_OPENBACKGROUND, 
		P_GAMEBACKGROUND, P_GAMEOVER,P_COIN, P_FIRSTLEVELBACKGROUND, P_GOLDENEGG,P_SCOREBOARD,
		P_LIFEPRESENT,P_SCOREPRESENT,P_TIMEPRESENT,P_WIN, P_SECONDLEVEL,P_THIRDLEVEL,P_HELP,P_GATE
		
};


using std::vector;

Resources::Resources()
{

	m_textureVec.resize(NUM_OF_PICTURES);
	m_textureVec[P_PLAYER].loadFromFile("player.png");
	m_textureVec[P_FIRINGMONSTER].loadFromFile("monster.png");
	m_textureVec[P_SECONDLEVEL].loadFromFile("level2.png");
	m_textureVec[P_THIRDLEVEL].loadFromFile("level3.png");
	m_textureVec[P_REGULARMONSTER].loadFromFile("RegularMonster.png");
	m_textureVec[P_OPENBACKGROUND].loadFromFile("startMenu.png");
	m_textureVec[P_GAMEOVER].loadFromFile("gameOver.png");
	m_textureVec[P_COIN].loadFromFile("coin.png");
	m_textureVec[P_FIRSTLEVELBACKGROUND].loadFromFile("firstLevel.png");
	m_textureVec[P_GOLDENEGG].loadFromFile("goldenEgg.png");
	m_textureVec[P_SCOREBOARD].loadFromFile("scoreBoard.png");
	m_textureVec[P_LIFEPRESENT].loadFromFile("LifePresent.png");
	m_textureVec[P_SCOREPRESENT].loadFromFile("scorePresent.png");
	m_textureVec[P_TIMEPRESENT].loadFromFile("TimePresent.png");
	m_textureVec[P_WIN].loadFromFile("win.png");
	m_textureVec[P_HELP].loadFromFile("help.png");
	m_textureVec[P_GATE].loadFromFile("gate.png");








	//---------font--------
	m_fontScoreBoard.loadFromFile("fontScore.otf");

	m_fontClock.loadFromFile("time.ttf");
	//
	if (!m_music.loadFromFile("musicGame.wav"))
		return ;
}
sf::SoundBuffer* Resources::getMusicGame()
{
	return &m_music;

}
sf::Texture* Resources::getPLAYERpic()
{
	return &m_textureVec[P_PLAYER];
}

sf::Texture* Resources::getGATEpic()
{
	return &m_textureVec[P_GATE];
}


sf::Texture* Resources::getTHIRDLEVELpic()
{
	return &m_textureVec[P_THIRDLEVEL];
}

sf::Texture* Resources::getScoreBoardpic()
{
	return &m_textureVec[P_SCOREBOARD];
}

sf::Texture* Resources::getPRESENTpic()
{
	return &m_textureVec[P_PRESENT];
}
sf::Texture* Resources::getFIRSTLEVELBACKGROUNDpic()
{
	return &m_textureVec[P_FIRSTLEVELBACKGROUND];
}

sf::Texture* Resources::getSECONDLEVELBACKGROUNDpic()
{
	return &m_textureVec[P_SECONDLEVEL];
}

sf::Texture* Resources::getOPENBACKGROUNDpic()
{
	return &m_textureVec[P_OPENBACKGROUND];
}

sf::Texture* Resources::getGOLDENEGGpic()
{
	return &m_textureVec[P_GOLDENEGG];
}

sf::Texture* Resources::getREGULARMONSTERpic()
{
	return &m_textureVec[P_REGULARMONSTER];
}

sf::Texture* Resources::getWINpic()
{
	return &m_textureVec[P_WIN];
}

sf::Texture* Resources::getFIRINGMONSTERpic()
{
	return &m_textureVec[P_FIRINGMONSTER];
}

sf::Texture* Resources::getGameBackground()
{
	return &m_textureVec[P_GAMEBACKGROUND];
}
sf::Texture* Resources::getGAMECOINpic()
{
	m_textureVec[P_COIN].setSmooth(true);
	return &m_textureVec[P_COIN];
}

sf::Font* Resources::getCLOCKFont()
{
	return &m_fontClock;
}

sf::Texture* Resources::getGAMEOVERpic()
{
	return &m_textureVec[P_GAMEOVER];
}

sf::Font* Resources::getFontScore()
{
	return &m_fontScoreBoard;
}
sf::Texture* Resources::getHELPpic()
{
	return &m_textureVec[P_HELP];
}

sf::Texture* Resources::getpresentpic(std::unique_ptr<StaticObject>& t)
{


	if (typeid(*t).name()==typeid(LifePresent).name())
	{
		return &m_textureVec[P_LIFEPRESENT];
	}
	
	if (typeid(*t) == typeid(TimePresent))
		return &m_textureVec[P_TIMEPRESENT];

	
	if (typeid(*t) == typeid(ScorePresent))
		return &m_textureVec[P_SCOREPRESENT];
}




