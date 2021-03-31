#include "ValidName.h"

ValidName::ValidName() {
	valid_name = "0";
}

std::string ValidName::get_valid_name() {

	std::string raw_input = "";

	while (!name_is_valid(raw_input))
		std::getline(std::cin, raw_input);

	valid_name = raw_input;
	return valid_name;
}

bool ValidName::name_is_valid(std::string& s) {
	return (content_is_valid(s) && size_is_valid(s));
}

bool ValidName::content_is_valid(std::string& s) {
	int bad_char = 0;
	for (int i = 0; i < s.length(); i++)
		if (!char_is_valid(s[i]))
		{
			bad_char++;
			break;
		}
	return (bad_char == 0);
}

bool ValidName::char_is_valid(char& c) {
	return (isalpha(c) || isdigit(c) || c == 95);
}

bool ValidName::size_is_valid(std::string& s) {
	return (s.length() >= 4 && s.length() <= 16);
}