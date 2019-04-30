#pragma once
#include <string>
#include <map>
#include <sstream>

class Properties
{
private:
	std::map<std::string, std::string> properties;
public:
	Properties(const std::string & filename);

	template<class T>
	T get(const std::string & key)
	{
		std::stringstream ss;
		ss << properties[key];
		T result;
		ss >> result;
		return result;
	}
};


