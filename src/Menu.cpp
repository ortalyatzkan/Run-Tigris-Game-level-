#include "Menu.h"

Menu::Menu()
{
	m_PhotoMenu.setTexture(*m_game.getMenu());
	m_gameOverPhoto.setTexture(*m_game.getGameOver());
	m_photoWin.setTexture(*m_game.getWinPic());
	m_photoHelp.setTexture(*m_game.getHELPpic());


//------------------------------------------------------------
	m_startButton.setSize(sf::Vector2f(225, 65));
	m_startButton.setFillColor(sf::Color::Transparent);
	m_startButton.setPosition(570, 510);
//-----------------------------------------------------------
	m_exitButton.setSize(sf::Vector2f(225, 70));
	m_exitButton.setFillColor(sf::Color::Transparent);

	m_exitButton.setPosition(570, 605);
//------------------------------------------------------------
	m_helpButton.setRadius(42);
	m_helpButton.setFillColor(sf::Color::Transparent);
	m_helpButton.setPosition(1, 6);
	
}

void Menu::openMenu()
{
	bool isGame = true, exited = false, enterPressed = false , firsttime=true;

	while (1)
	{
		m_menuWindow.create(sf::VideoMode(950, 800), "RunTigris");
		while (m_menuWindow.isOpen())
		{
			m_menuWindow.clear();
			m_menuWindow.draw(m_PhotoMenu);
			m_menuWindow.draw(m_startButton);
			m_menuWindow.draw(m_exitButton);
			m_menuWindow.draw(m_helpButton);

			m_menuWindow.display();



			if (auto event = sf::Event{}; m_menuWindow.pollEvent(event))
			{
				
				switch (event.type)
				{
				case (sf::Event::EventType::Closed):
				{
					m_menuWindow.close();
					return;

				}
				case (sf::Event::EventType::MouseButtonPressed):
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if (!firsttime)
						if (m_exitButton.getGlobalBounds().contains(m_menuWindow.mapPixelToCoords
						(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
							m_menuWindow.close();
							return;
						}

						if (m_startButton.getGlobalBounds().contains(m_menuWindow.mapPixelToCoords
						(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
						{
							m_game.resetLevels();
							m_menuWindow.close();
							while (isGame)
							{
								firsttime = false;
								isGame = m_game.run(exited);
								if (!isGame)
									break;

								if (m_game.getLevel() == 2) {
									m_menuWindow.close();
									win();
									break;
								}

								m_game.restart();

								if (exited) {
									m_game.resetLevels();
									exited = false;
									break;
								}

							}
							if (!isGame) {
								m_menuWindow.create(sf::VideoMode(950, 700), "RunTigris");//game over
								isGame = true;

								while (m_menuWindow.isOpen())
								{
									auto event = sf::Event{};
									while ( m_menuWindow.pollEvent(event))
									{
										m_menuWindow.draw(m_gameOverPhoto);
										m_menuWindow.display();
										switch (event.type)
										{
										case (sf::Event::EventType::Closed):
										{
											m_menuWindow.close();
											m_game.resetLevels();

											break;
										}

										}
										m_game.resetLevels();
										break;

									}
									isGame = true;


								}
								isGame = true;
							}

						}

						if (m_helpButton.getGlobalBounds().contains(m_menuWindow.mapPixelToCoords
						(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
						{
							while (m_menuWindow.isOpen())
							{
								m_menuWindow.clear();
								m_menuWindow.draw(m_photoHelp);
								m_menuWindow.display();

								if (auto event = sf::Event{}; m_menuWindow.pollEvent(event))
								{
									switch (event.type)
									{
									case (sf::Event::EventType::Closed):
									{
										m_menuWindow.close();
										return;

									}
									case(sf::Event::KeyPressed):
									{
										if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
											enterPressed = true;
									}
									
									}
									if (enterPressed) {
										enterPressed = false;
										break;
									}
								}


							}

						}
						m_menuWindow.clear();
						m_menuWindow.draw(m_PhotoMenu);
						m_menuWindow.draw(m_startButton);
						m_menuWindow.draw(m_exitButton);
						m_menuWindow.draw(m_helpButton);

						m_menuWindow.display();
					}
				}

			}
		}
	}
}

void Menu::win()
{
	m_menuWindow.create(sf::VideoMode(950, 800), "RunTigris");
	m_menuWindow.draw(m_photoWin);
	m_menuWindow.display();
	while (m_menuWindow.isOpen())
	{
		if (auto event = sf::Event{}; m_menuWindow.pollEvent(event))
		{
			m_menuWindow.draw(m_photoWin);
			m_menuWindow.display();
			switch (event.type)
			{
			case (sf::Event::EventType::Closed):
			{
				m_game.resetLevels();
				m_menuWindow.close();
			}
			}
		}


	}
}
