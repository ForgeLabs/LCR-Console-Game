#ifndef PLAYERGROUP_H
#define PLAYERGROUP_H

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "ValidName.h"

class PlayerGroup
{
public:

	PlayerGroup();
	PlayerGroup(std::string, int);
	PlayerGroup(int);

#pragma region Mutaor functions
	void set_name(std::string);
	void set_playercount(int);
	void populate_group();
	void list_player_stats();
#pragma endregion

#pragma region Accessor functions
	std::string get_name();
	int get_playercount();
	Player& get_player(int);
#pragma endregion

private:
	std::vector<Player> group;
	std::string name;
	int playercount;

};
#endif