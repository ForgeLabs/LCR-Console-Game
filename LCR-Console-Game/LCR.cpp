#include "LCR.h"

LCR::LCR() {
	set_game_is_won(false);
	srand(time(0)); // ONLY CALL ONCE FOR THE ENTIRE PROGRAM
}

void LCR::initialize_game() {
	DBM.create_table();
	LCR_players.populate_group();
}

void LCR::make_move(Player& p)
{
	int r = check_dice_rolls(p);
	for (int i = 0; i < r; i++)
	{
		int score_before_roll = p.get_score(); //placeholder for score query
		die.roll_die();
		distribute_chip(p);
		int score_after_roll = p.get_score();

		//Output results to console, if a player wins, set the win condition
		std::cout << p.get_name() << " rolled a " << die.get_face() << " score: " << p.get_score() << std::endl;
		bool b = false;
		/*if (check_for_winner())
			set_winner();*/

			//Check for winning player, query server
			//b = (get_winner().get_name() == p.get_name());
		DBM.insert_into_table(p.get_name(), score_before_roll, die.get_face(), score_after_roll, b);
	}
}

//Ensures player can not roll more dice than they have
int LCR::check_dice_rolls(Player& p) {

	int x = p.get_score();

	if (x >= 3)
		return 3;
	else if (x == 2)
		return 2;
	else if (x == 1)
		return 1;
	else return 0;

}

void LCR::play_game()
{
	initialize_game();

	while (!check_for_winner())
	{
		play_round();
	}

	set_winner();

	DBM.insert_into_table(winner.get_name(), winner.get_score(), 'W', winner.get_score(), true);

	list_game_report();

	LCR_players.list_player_stats();
}

void LCR::remove_chip(Player& p) {
	p.decrease_score(1);
}

void LCR::add_chip(Player& p) {
	p.increase_score(1);
}

//Removes chip from current player and gives it to the adject player
void LCR::distribute_chip(Player& p) {

	if ((die.get_value() % 2) != 0) //rolled an odd (subtract chip)
		remove_chip(p);

	if (p.is_left_most_player() && die.get_value() == 1) //left player rolls left
		add_chip(LCR_players.get_player(LCR_players.get_playercount() - 1));
	else if (p.is_right_most_player() && die.get_value() == 5) //right player rolls right
		add_chip(LCR_players.get_player(0));
	else if (die.get_value() == 1) //any player rolls left
		add_chip(LCR_players.get_player(p.get_place() - 1));
	else if (die.get_value() == 5) //any player rolls right
		add_chip(LCR_players.get_player(p.get_place() + 1));
}

//Each player makes one move
void LCR::play_round() {

	for (int i = 0; i < LCR_players.get_playercount(); i++) {
		make_move(LCR_players.get_player(i));
	}
	this->advance_round();
}

//loop through players, if one exists, return true, else false
bool LCR::check_for_winner() {

	int num_positive_players = 0;

	for (int i = 0; i < LCR_players.get_playercount(); i++) {
		if (LCR_players.get_player(i).get_score() >= 1)
			num_positive_players++;
	}

	if (num_positive_players == 1)
		return true;
	else
		return false;
}

void LCR::list_round() {
	std::cout << "Round: " << this->get_game_round() << std::endl;
}

void LCR::list_game_report() {
	std::cout << get_winner().get_name() << " won the game in " << get_game_round()
		<< " rounds." << std::endl;
}

Player& LCR::get_winner() {
	return winner;
}

void LCR::set_winner() {
	for (int i = 0; i < LCR_players.get_playercount(); i++) {
		if (LCR_players.get_player(i).get_score()) { //if true, this is location of the winner
			winner = LCR_players.get_player(i);
			break;
		}
	}
}
