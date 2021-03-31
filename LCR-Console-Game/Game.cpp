#include "Game.h"

Game::Game() {
	game_is_won = false;
	game_round = 0;
}

bool Game::get_game_is_won() {
	return game_is_won;
}

void Game::set_game_is_won(bool b) {
	game_is_won = b;
}

int Game::get_game_round() {
	return game_round;
}

void Game::advance_round() {
	game_round++;
}