#include "File.h"
#include <sstream>


const int NUM_OF_LEVELS = 3;

File::File()
{
	m_levelFile.open("levels.txt");
	if (!m_levelFile.is_open())
		throw ifstream::failure("Exception opening/reading file");
	readLevels();

}

void File::readLevels()
{
	string temp;
	ifstream openFileHelper;
	string name;
	m_levelsVec.resize(NUM_OF_LEVELS);
	for (int i = 0; i < NUM_OF_LEVELS; i++) {
		std::getline(m_levelFile, name);
		openFileHelper.open(name);
		if (!openFileHelper.is_open())
			throw ifstream::failure("Exception opening/reading file\n");

		while (!openFileHelper.eof())
		{
			std::getline(openFileHelper, temp);
			m_levelsVec[i].push_back(temp);

		}
		openFileHelper.close();
	}


}

vector<string> File::getLevel(const size_t& i)
{
	return m_levelsVec[i];
}