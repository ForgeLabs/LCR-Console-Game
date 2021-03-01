#include "PlayerGroup.h"

PlayerGroup::PlayerGroup() {
	playercount = 0;
	name = "null";
}

PlayerGroup::PlayerGroup(std::string n, int c) {
	name = n;
	playercount = c;
	group.resize(playercount);
}

PlayerGroup::PlayerGroup(int c) {
	playercount = c;
	group.resize(playercount);
}

std::string PlayerGroup::get_name() {
	return name;
}

void PlayerGroup::set_name(std::string n) {
	name = n;
}

int PlayerGroup::get_playercount() {
	return playercount;
}

void PlayerGroup::set_playercount(int c) {
	playercount = c;
	group.resize(playercount);
}

void PlayerGroup::populate_group() {

	std::cout << "How many players are playing?" << std::endl;

	std::cin >> playercount;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	group.resize(playercount);

	ValidName temp_name;

	for (int i = 0; i < playercount; i++)
	{
		std::cout << "Enter player " << i + 1 << "s name:" << std::endl;

		std::string clean_name = temp_name.get_valid_name();

		Player new_player;

		group.push_back(new_player);

		get_player(i).set_name(clean_name);
		get_player(i).set_place(i);

		//get_player(i).set_is_left_most_player(i);
		if (get_player(i).get_place() == 0)
			get_player(i).set_left_most();
		else if (get_player(i).get_place() == (playercount - 1))
			get_player(i).set_right_most();
	}
}

void PlayerGroup::list_player_stats() {

	for (int i = 0; i < get_playercount(); i++)
	{
		std::cout << (group[i]).get_name() << ": " << group[i].get_score() << " is " << group[i].is_left_most_player() << group[i].is_right_most_player() << std::endl;
	}
}

Player& PlayerGroup::get_player(int i)
{
	return group[i];
}