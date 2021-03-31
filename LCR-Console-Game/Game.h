#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "PlayerGroup.h"

#include <iostream>
#include <string>

class Game
{
public:

	Game();

	bool get_game_is_won();
	void set_game_is_won(bool);

	int get_game_round();
	void advance_round();

private:

	bool game_is_won;
	int game_round;
};

#endif