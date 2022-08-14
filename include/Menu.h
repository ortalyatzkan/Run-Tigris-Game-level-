#pragma once
#include "Controller.h"
#include <SFML/Graphics.hpp>


class Menu
{
public:
	Menu();
	void openMenu();
	void win();
	


private:
	Controller m_game;
	sf::RenderWindow m_menuWindow;
	sf::Sprite m_photoWin;
	sf::Sprite m_photoHelp;
	sf::Sprite m_PhotoMenu;
	sf::Sprite m_gameOverPhoto;
	sf::RectangleShape m_startButton;
	sf::RectangleShape m_exitButton;
	sf::CircleShape m_helpButton;
	


	
};