#include "Controller.h"
#include "Egg.h"
#include <sstream>
#include "Coin.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

struct point
{
	int x, y;
};


bool Controller::run(bool& exited)
{
	m_player.setLives();
	m_window.create(sf::VideoMode(1500, 800), "RunTigris");
	buildBoard();
	m_gameMusic.play();

	sf::Sprite photo;
	getPhotoLevel(photo);//this function load photo of backgrowd of level
	
	m_window.pushGLStates();
	auto view = sf::View(sf::FloatRect(0.f, 0.f, 1500.f, 800.f));

	sf::Event event;
	bool  keyboard = false, isRight = true;
	m_clock.restart();

	sf::Time time;
	sf::Time gameTime;
	int TimeClock=70;
	gameTime = m_clock.getElapsedTime();
	createText(gameTime, TimeClock);
	sf::Sprite gate;
	gate.setTexture(*m_resource.getGATEpic());
	sf::Vector2f pos(5770, 500);
	gate.setPosition(pos);


	sf::Vector2f m_direction;
	float deltaTime;

	m_player.locOfFrame( isRight);

//-----------------------------

	for (int i = 0; i < m_vecMonster.size(); i++) {
		bool isRight = true;
		m_vecMonster[i]->locOfFrame( isRight);
	}
//-----------------------------
	m_window.draw(photo);
	 
	m_window.draw(m_player.getSprite());
	deltaTime = m_clock.getElapsedTime().asSeconds();

	m_timeGame = 70 - (int)time.asSeconds();
	

	while (m_window.isOpen())
	{
		
		time = m_clock.getElapsedTime();

		if (m_player.getLives() < 0 || m_timeGame<=0)
		{

			m_gameMusic.stop();
			m_window.close();
			return false;
		}

		if (m_player.getPosition().x > 5800.f && m_player.getNumOfScore() >= 200)
		{
			m_gameMusic.stop();
			m_window.close();
			m_player.setLives();

			return true;
		}


		if (auto event = sf::Event{}; m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case (sf::Event::EventType::Closed):
				m_window.close();
				m_gameMusic.stop();
				exited = true;
				break;

			case sf::Event::KeyPressed:
			{

				if (event.key.code == sf::Keyboard::Right)
				{
					if (m_player.getPosition().x < 5870.f)
					{
						m_player.move(D_RIGHT);
					}
					keyboard = true;
					isRight = true;
				}

				if (event.key.code == sf::Keyboard::Left)
				{
					if (m_player.getPosition().x > 120.f)
						m_player.move(D_LEFT);

					keyboard = true;
					isRight = false;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					float speed = 110;
					sf::Vector2f temp;
					sf::Vector2f movement(0, 0);

					while (m_player.getPosition().y > 480)//goes up
					{
						sf::Vector2f Left(-1.2f, 1.2f);
						if (m_player.getSprite().getScale() == Left)
							movement.x -= speed * deltaTime / 2.5;
						else
							movement.x += speed * deltaTime / 5;

						movement.y -= speed * deltaTime;

						m_player.moveF(movement);
						sf::IntRect rect(0, 0, 100, 110);

						m_player.moveFrame( 600, 100, isRight, time);

						for (int i=0 ; i<m_vecMonster.size();i++)
						{
							m_vecMonster[i]->moveFrame( 770, 110, isRight, time);
							m_vecMonster[i]->move();
							m_window.draw(m_vecMonster[i]->getSprite());
						}

						if(m_player.getNumOfScore()<200)
						m_window.draw(gate);

						collisionMonsterPlayer(isRight);
						collisionCoin(isRight, TimeClock);

						for(int i=m_numOfFiringMonster ; i<m_staticObj.size(); i++)
							m_window.draw(m_staticObj[i]->getSprite());

						time = m_clock.getElapsedTime();
						createText(time, TimeClock);
						for (int i = 0; i < m_staticObj.size(); i++)
							if (m_staticObj[i]->isFalling()) {
								m_staticObj[i]->falling(m_staticObj[i]->getPosition());
								m_window.draw(m_staticObj[i]->getSprite());
							}
						drawBoard(view, photo, isRight, time,gate);
						if (m_player.getNumOfScore() < 200)
							m_window.draw(gate);
					}

					while (m_player.getPosition().y < 580)//goes down
					{
						collisionMonsterPlayer(isRight);
						collisionCoin(isRight, TimeClock);
						movement.y += speed * deltaTime;
						movement.x += speed * deltaTime / 6;

						m_player.moveF(movement);

						for (int i=0 ;i< m_vecMonster.size() ;i++)
						{
							m_vecMonster[i]->moveFrame( 770, 110, isRight, time);
							m_vecMonster[i]->move();
						}

						for (int i=0; i< m_staticObj.size(); i++)
							if (m_staticObj[i]->isFalling()) {
								m_staticObj[i]->falling(m_staticObj[i]->getPosition());
								m_window.draw(m_staticObj[i]->getSprite());
							}
						
						time = m_clock.getElapsedTime();
						createText(time, TimeClock);
						drawBoard(view,  photo, isRight, time,gate);
						if (m_player.getNumOfScore() < 200)
							m_window.draw(gate);

						collisionMonsterPlayer(isRight);
						collisionCoin(isRight, TimeClock);
					
						for (int i = m_numOfFiringMonster; i < m_staticObj.size(); i++)
							m_window.draw(m_staticObj[i]->getSprite());
					}
				}
				break;

			}

			default:
				sf::IntRect t;
				t.height = m_player.getSpriteSize().height;
				t.width = m_player.getSpriteSize().width;
				t.left = 0;
				t.top = 0;
				m_player.setSpriteSize(t);
			}

			m_window.draw(m_gameBoard.getSpriteScoreBoard());

			m_player.locOfFrame( isRight);

			if (keyboard == true)
			{
				m_player.moveFrame( 600, 100, isRight, time);
				keyboard = false;
			}


		}
		gameTime = m_clock.getElapsedTime();
		createText(gameTime, TimeClock);

		sf::Vector2f position(1500, 800);
		sf::Vector2f MapPosition(position.x / 2, position.y);

		MapPosition.x = m_player.getSprite().getPosition().x + 10 - (position.x / 2);
		MapPosition.y = m_player.getSprite().getPosition().y + 10 - (position.y);
		collisionMonsterPlayer(isRight);

		if (MapPosition.x < 0)
			MapPosition.x = 0;

		if (MapPosition.y <= 0)
			MapPosition.y = 0;
		if (m_player.getNumOfScore() < 200)
			m_window.draw(gate);

		if (MapPosition.x < 4500.f)
			view.reset(sf::FloatRect(MapPosition.x, MapPosition.y, position.x, position.y));

		m_window.setView(view);
		m_window.draw(photo);
		m_window.draw(m_time);
 

		if (  MapPosition.x < 0|| MapPosition.x < 4500.f)
		{
			gameTime = m_clock.getElapsedTime();
			sf::Vector2f pos(MapPosition.x + 50, MapPosition.y + 10);
			m_gameBoard.setPositionScore(pos);
			m_textScore.setPosition(pos.x+570,pos.y+55);
			m_textLives.setPosition(pos.x + 170, pos.y + 54);
			m_time.setPosition(pos.x + 1225, pos.y + 50);
			
			
		}

		for (int i = m_numOfFiringMonster; i < m_staticObj.size(); i++)
			m_window.draw(m_staticObj[i]->getSprite());

		for (int i = 0; i < m_vecMonster.size(); i++)
		{
			m_vecMonster[i]->moveFrame( 770, 110, isRight, time);
			m_vecMonster[i]->move();
			if(i < m_numOfFiringMonster)
				m_staticObj[i]->falling(m_vecMonster[i]->getPosition());

			m_window.draw(m_vecMonster[i]->getSprite());
			gameTime = m_clock.getElapsedTime();

			if(i < m_numOfFiringMonster)
				if (m_staticObj[i]->isFalling()) {
					m_staticObj[i]->falling(m_staticObj[i]->getPosition());
					m_window.draw(m_staticObj[i]->getSprite());
				}
			
		}
		
		for (int i = m_numOfFiringMonster; i < m_staticObj.size(); i++)
			m_window.draw(m_staticObj[i]->getSprite());

		m_window.draw(m_player.getSprite());
		for (int i=0 ; i<m_staticObj.size() ; i++)
			if (m_staticObj[i]->isFalling()) {
				m_staticObj[i]->falling(m_staticObj[i]->getPosition());
				m_window.draw(m_staticObj[i]->getSprite());
			}
		
		m_window.draw(m_gameBoard.getSpriteScoreBoard());
		m_window.draw(m_textScore);
		m_window.draw(m_textLives);
		m_window.draw(m_time);
		if ( m_player.getNumOfScore()>=200)
			m_window.draw(gate);
			


		m_window.display();

		m_window.clear();
		collisionCoin(isRight, TimeClock);
		collisionMonsterPlayer(isRight);
	
	}
	return true;
}

void Controller::buildBoard()
{
	auto view = sf::View(sf::FloatRect(0.f, 0.f, 1500.f, 800.f));
	m_window.setView(view);
	m_window.setFramerateLimit(40);
	//----------------------fonts--------------------------
	m_textScore.setFont(*m_resource.getFontScore());
	m_textLives.setFont(*m_resource.getFontScore());
	m_gameMusic.setBuffer(*m_resource.getMusicGame());

	//-------------------resets of other members------------------
	Player temp(m_resource.getPLAYERpic());
		m_numOfFiringMonster = m_gameBoard.getNumOfFiringMonster();

	m_player = temp;
	m_gameBoard.setPositionPlayer(m_player);
	m_gameBoard.setPositionMonster(m_vecMonster, m_staticObj);
	m_gameBoard.setCoinPosition(m_staticObj);
	m_gameBoard.setPresentPosition(m_staticObj);

	int loc = 0;

	for (int i = 0; i < m_numOfFiringMonster; i++)
	{
		m_vecMonster[i]->setTexture(m_resource.getFIRINGMONSTERpic());
		loc = i;
	}
	loc++;
	
	for (int i = loc; i < m_vecMonster.size(); i++)
	{
		m_vecMonster[i]->setTexture(m_resource.getREGULARMONSTERpic());
		loc = i;
	}

	for (int i = 0; i < m_staticObj.size(); i++)
	{
		
		if(typeid(*m_staticObj[i])==typeid(Egg))
			m_staticObj[i]->setTexture(m_resource.getGOLDENEGGpic());
		if (typeid(*m_staticObj[i]) == typeid(Coin))
			m_staticObj[i]->setTexture(m_resource.getGAMECOINpic());
		
		if (typeid(*m_staticObj[i]) == typeid(ScorePresent) ||
			typeid(*m_staticObj[i]) == typeid(TimePresent) ||
			typeid(*m_staticObj[i]) == typeid(LifePresent))
		{

			m_staticObj[i]->setTexture(m_resource.getpresentpic(m_staticObj[i]));
		}
	}
	m_gameBoard.setTextureScoreBoard(m_resource.getScoreBoardpic());
	
	m_player.setLives();

}

sf::Texture* Controller::getMenu()
{
	return m_resource.getOPENBACKGROUNDpic();
}

sf::Texture* Controller::getGameOver()
{
	return m_resource.getGAMEOVERpic();
}

sf::Texture* Controller::getWinPic()
{
	return m_resource.getWINpic();
}

sf::Texture* Controller::getHELPpic()
{
	return m_resource.getHELPpic();
}

void Controller::getPhotoLevel(sf::Sprite& photo)
{
	if (m_gameBoard.getLevel() == 0)
		photo.setTexture(*m_resource.getFIRSTLEVELBACKGROUNDpic());
	if (m_gameBoard.getLevel() == 1)
		photo.setTexture(*m_resource.getSECONDLEVELBACKGROUNDpic());
	if (m_gameBoard.getLevel() == 2)
		photo.setTexture(*m_resource.getTHIRDLEVELpic());
}

void Controller::drawBoard(sf::View view,  sf::Sprite photo, 
							bool isRight, sf::Time& time,sf::Sprite s)
{
	m_window.setView(view);
	m_window.draw(photo);
	for (int i = m_numOfFiringMonster; i < m_staticObj.size(); i++)
		m_window.draw(m_staticObj[i]->getSprite());

	for (int i = 0; i < m_vecMonster.size(); i++)
	{
		m_vecMonster[i]->moveFrame( 770, 110,  isRight, time);
		m_vecMonster[i]->move();
		m_window.draw(m_vecMonster[i]->getSprite());
	}

	m_window.draw(m_gameBoard.getSpriteScoreBoard());
	m_window.draw(m_textLives);
	m_window.draw(m_textScore);
	m_window.draw(s);
	m_window.draw(m_time);

	for (int i = 0; i < m_staticObj.size(); i++)//print present
	{
		m_window.draw(m_staticObj[i]->getSprite());
		if (m_staticObj[i]->isFalling()) 
			m_window.draw(m_staticObj[i]->getSprite());
	}
	m_window.draw(m_player.getSprite());

	m_window.display();
	m_window.clear();
}


void  Controller::createText(sf::Time time, const int TimeClock)
{
	
	std::stringstream stringText;
	stringText << m_player.getNumOfScore();
	m_textScore.setString(stringText.str());
	m_textScore.setCharacterSize(35); // in pixels, not points!
	m_textScore.setFillColor(sf::Color::Black);

	std::stringstream stringTextLives;
	stringTextLives << m_player.getNumOfLives();
	m_textLives.setString(stringTextLives.str());
	m_textLives.setCharacterSize(35); // in pixels, not points!
	m_textLives.setFillColor(sf::Color::Black);

	printTime(time, TimeClock);
}

void Controller::collisionMonsterPlayer(const bool isRight)
{
	float farX = m_player.getPosition().x + m_player.getSpriteSize().width;
	float topY = m_player.getPosition().y - m_player.getSpriteSize().height;
	float smallerX = m_player.getPosition().x - m_player.getSpriteSize().width;

	
	for (int i = m_numOfFiringMonster; i < m_vecMonster.size(); i++)
	{
		float smallMonsterX = m_vecMonster[i]->getSprite().getPosition().x -
			m_vecMonster[i]->getSprite().getGlobalBounds().width;
		float monsterX = m_vecMonster[i]->getSprite().getPosition().x +
			m_vecMonster[i]->getSprite().getLocalBounds().width;


		if (isRight && m_player.getPosition().y >= m_vecMonster[i]->getPosition().y &&
			m_vecMonster[i]->getPosition().x >= m_player.getPosition().x)

			if ((m_vecMonster[i]->getPosition().x <= farX ||
				monsterX <= m_player.getPosition().x) || 
					100 >= m_vecMonster[i]->getPosition().x - farX)
			{
				m_player.lessLife();
				m_player.setPosition(m_player.getFirstPosition());
				return;
			}

		else if (!isRight && (smallerX <= m_vecMonster[i]->getSprite().getPosition().x && 
			smallerX >= smallMonsterX || smallMonsterX <= m_player.getPosition().x && smallMonsterX >= smallerX))
			{
				m_player.lessLife();
				m_player.setPosition(m_player.getFirstPosition());
				return;
			}
	}
}

void Controller::collisionCoin(const bool isRight, int& TimeClock)
{
	float farX = m_player.getPosition().x + m_player.getSpriteSize().width;
	float topY = m_player.getPosition().y - m_player.getSpriteSize().height;

	for (int i = 0; i < m_staticObj.size(); i++)
	{
		float coinX = m_staticObj[i]->getSprite().getPosition().x +
			m_staticObj[i]->getSprite().getGlobalBounds().width;

		if ((isRight && m_staticObj[i]->getPosition().x >= m_player.getPosition().x &&
			m_staticObj[i]->getPosition().x <= farX) || (coinX <= farX &&
				coinX >= m_player.getPosition().x)) {

			if (topY <= m_staticObj[i]->getSprite().getPosition().y) {

				m_clock.getElapsedTime().asSeconds();
				TimeClock += m_staticObj[i]->doAction(m_player);
				if (typeid(*m_staticObj[i]) == typeid(TimePresent) || typeid(*m_staticObj[i]) == typeid(Coin) ||
					typeid(*m_staticObj[i]) == typeid(ScorePresent) || typeid(*m_staticObj[i]) == typeid(LifePresent))
				{
					m_staticObj.erase(m_staticObj.begin() + i);
					return;
				}
				else
					m_staticObj[i]->setPosition(m_vecMonster[i]->getPosition());
			}
		}

		else if (!isRight && m_player.getPosition().x <= coinX &&
			m_player.getPosition().x >= m_staticObj[i]->getSprite().getPosition().x)
			if (topY <= m_staticObj[i]->getSprite().getPosition().y) {

				m_clock.getElapsedTime().asSeconds();
				TimeClock += m_staticObj[i]->doAction(m_player);
				if (typeid(*m_staticObj[i]) == typeid(TimePresent) || typeid(*m_staticObj[i]) == typeid(Coin) ||
					typeid(*m_staticObj[i]) == typeid(ScorePresent) || typeid(*m_staticObj[i]) == typeid(LifePresent))
				{

					m_staticObj.erase(m_staticObj.begin() + i);
					return;
				}
				else
					m_staticObj[i]->setPosition(m_vecMonster[i]->getPosition());
			}

	}
}

void Controller::printTime(sf::Time t, const int TimeClock)
{
	std::stringstream ss;
	m_timeGame = TimeClock - (int)t.asSeconds();
	ss << "Time: " << m_timeGame << std::endl;
	m_time.setFont(*m_resource.getCLOCKFont());
	m_time.setString(ss.str());
	m_time.setCharacterSize(40);
	m_time.setColor(sf::Color::Black);
	
}

void Controller::restart()
{
	m_vecMonster.clear();
	m_staticObj.clear();
	m_gameBoard.delBoard();
	m_gameBoard.setLevel();
	m_gameBoard.buildBoard();

}

void Controller::resetLevels()
{
	m_vecMonster.clear();
	m_staticObj.clear();
	m_gameBoard.getFirstLevel();
	m_clock.restart();
	m_player.setLives();

}

