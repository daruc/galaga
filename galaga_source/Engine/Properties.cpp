#include "Properties.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <sstream>

std::string trim(const std::string & str)
{
	std::stringstream strStream;
	for (const char & ch : str)
	{
		if (!isblank(ch))
		{
			strStream << ch;
		}
	}
	return strStream.str();
}

Properties::Properties(const std::string & filename)
{
	std::ifstream inFile(filename);

	std::string line;
	while (std::getline(inFile, line))
	{
		int index = line.find('=');
		std::string key = line.substr(0, index);
		std::string value = line.substr(index + 1);

		key = trim(key);
		value = trim(value);
		properties[key] = value;
	}

}

