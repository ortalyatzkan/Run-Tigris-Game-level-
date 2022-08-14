#include <iostream>
#include <fstream>
#include<vector>
#include <cstring>


using std::string;
using std::ifstream;
using std::vector;


class File
{
public:
	File();
	void readLevels();
	std::vector<string> getLevel(const size_t&);
	~File() { m_levelFile.close(); }

private:
	ifstream m_levelFile;
	vector<vector<string>> m_levelsVec;


};