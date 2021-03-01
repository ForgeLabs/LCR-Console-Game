#ifndef DIE_H
#define DIE_H

#include <iostream>
#include <ctime>

class Die
{
public:

	Die();

	void roll_die();

	int get_value();
	char get_face();

private:
	int value;
	char face;

};
#endif