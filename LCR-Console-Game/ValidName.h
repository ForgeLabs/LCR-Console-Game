#ifndef VALIDNAME_H
#define VALIDNAME_H

#include <iostream>
#include <string>
#include <climits>

class ValidName
{

public:

	ValidName();

	//Loop till valid name is entered
	std::string get_valid_name();

	//Size, and characters valid
	bool name_is_valid(std::string&);

	//Chars are all valid size can be off
	bool content_is_valid(std::string&);

	//Input only alpha-numeric-underscores
	bool char_is_valid(char&);

	//Input length 4 - 16
	bool size_is_valid(std::string&);

private:
	std::string valid_name;
};

#endif