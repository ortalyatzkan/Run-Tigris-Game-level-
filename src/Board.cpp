
#include "Board.h"

Board::Board(): m_level(0)
{
	m_boardGame.resize(m_file.getLevel(m_level).size());
	buildBoard();

}

void Board::buildBoard()
{
	m_boardGame = m_file.getLevel(m_level);
	sf::Vector2f loc(1000, 100000.f);
	//setPositionScore(loc);
}


void Board::setPositionScore(sf::Vector2f loc)
{
	m_scoreBoard.setPosition(loc);
}

void Board::setPositionPlayer(Player& p)
{
	for (size_t i =m_boardGame.size()-1; i >0 ; i--)
		for (size_t j = 0; j <m_boardGame[i].size(); j++)
			if (m_boardGame[i][j] == '!') {
				int x, y;
				x = i, y = j;

				sf::Vector2f vec(100* y, x*100-130);
				p.setPosition(vec);
				p.setFirsPosition(vec);
				return;
			}
}

void Board::setPositionMonster(std::vector<std::unique_ptr<Monster>>& monster,
	std::vector<std::unique_ptr<StaticObject>>& egg)
{
	int index = 0;
	
	for (int i=m_boardGame.size()-1 ; i >= 0; i--)
		
		for (int j = 0; j < m_boardGame[i].size(); j++)
			if (m_boardGame[i][j] == '%') {
				int x, y;
				x = i, y = j;
				sf::Vector2f vect(y* 100, x * 100-130);

				monster.push_back(std::make_unique <FiringMonster>());
				monster[index]->setPosition(vect);
				egg.push_back ( std::make_unique <Egg>());
				vect.y += 20;
				egg[index]->setPosition(vect);
				
				index++;
			}


	for (int i = m_boardGame.size() - 1; i >= 0; i--)
	{

		for (int j = 0; j < m_boardGame[i].size(); j++)
			if (m_boardGame[i][j] == '*') {
				int x, y;
				x = i, y = j;
				sf::Vector2f vect(y * 100, x * 100-150);

				monster.push_back(std::make_unique <RegularMonster>());
				monster[index]->setPosition(vect);

				index++;
			}
	}

}

void Board:: setTextureScoreBoard(sf::Texture* t)
{
	m_scoreBoard.setTexture(*t);
}

void Board::setCoinPosition(std::vector<std::unique_ptr<StaticObject>>& coins)
{
	int index = getNumOfFiringMonster();
	for (int i = 0; i < m_boardGame.size(); i++)
		for (int j = 0; j < m_boardGame[i].size(); j++)
			if (m_boardGame[i][j] == '$') {
				int x, y;
				x = i, y = j;
				sf::Vector2f temp (y*100, x*100-130);
				coins.push_back(std::make_unique<Coin>());
				coins[index]->setPosition(temp);
				index++;
			}
	m_numCoins = index ;

}

int Board::getNumOfFiringMonster()
{
	int count = 0;
	for (int i = m_boardGame.size() - 1; i >= 0; i--)
		for (int j = 0; j < m_boardGame[i].size(); j++)
			if (m_boardGame[i][j] == '%') 
				count++;
			
	return count;
}


void Board::setPresentPosition(std::vector<std::unique_ptr<StaticObject>>& present)
{
	size_t index = m_numCoins;
	int count = 0;
	for (int i = m_boardGame.size() - 1; i >= 0; i--)

		for (int j = 0; j < m_boardGame[i].size(); j++)
		{
			if (m_boardGame[i][j] == 't')
			{
				int x, y;
				x = i, y = j;
				sf::Vector2f temp(y * 100, x * 100-130);

				present.push_back(std::make_unique<TimePresent>());
				present[index]->setPosition(temp);
				index++;

			}
			else if (m_boardGame[i][j] == 'c')
			{
				int x, y;
				x = i, y = j;
				sf::Vector2f temp(y * 100, x * 100-130);

				present.push_back(std::make_unique<ScorePresent>());
				present[index]->setPosition(temp);
				index++;

			}
			else if (m_boardGame[i][j] == 'l')
			{
				int x, y;
				x = i, y = j;
				sf::Vector2f temp(y * 100 ,x * 100-130);

				present.push_back(std::make_unique<LifePresent>());
				present[index]->setPosition(temp);
				index++;

			}
		
		}
	
	int lifePresentCount = 0, scorePresentCount = 0, timePresentCount = 0;
	for (int i = 0; i < present.size(); i++) {
		if (typeid(*present[i]) == typeid(LifePresent))
			lifePresentCount++;

		if (typeid(*present[i]) == typeid(TimePresent))
			timePresentCount++;

		if (typeid(*present[i]) == typeid(ScorePresent))
			scorePresentCount++;
	}

}
