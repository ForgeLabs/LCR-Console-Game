#ifndef LCR_H
#define LCR_H

#include "mysql.h"
#include "DatabaseManager.h"
#include "ValidName.h"
#include "Game.h"
#include "LCR.h"
#include "Player.h"
#include "PlayerGroup.h"
#include "Die.h"
#include <sstream> //to_string()

class LCR : public Game
{

public:
	LCR();

	DatabaseManager DBM;

	void initialize_game();
	void make_move(Player&);
	void remove_chip(Player&);
	void add_chip(Player&);
	void distribute_chip(Player&);
	void play_round();
	void play_game();
	void list_round();
	void list_game_report();
	void set_winner();

	int check_dice_rolls(Player&);
	bool check_for_winner();
	Player& get_winner();

private:
	Player winner;
	Die die;
	PlayerGroup LCR_players;
};

#endif