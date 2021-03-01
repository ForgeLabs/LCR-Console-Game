#include "Player.h"

Player::Player() {
    name = "null";
    score = 3;
    place = 0;
    left_most_player = false;
    right_most_player = false;
}

Player::Player(std::string n) {
    name = n;
    score = 3;
    place = 0;
    left_most_player = false;
    right_most_player = false;
}

std::string Player::get_name() {
    return name;
}

void Player::set_name(std::string& n) {
    name = n;
}

int Player::get_score() {
    return score;
}

void Player::set_score(int s) {
    score = s;
}

void Player::increase_score(int s) {
    score += s;
}

void Player::decrease_score(int s) {
    score -= s;
}

void Player::set_place(int i) {
    place = i;
}

int Player::get_place()
{
    return place;
}

void Player::set_left_most() //whenever called, sets the value automatically
{
    left_most_player = true;
}

void Player::set_right_most() //whenever called, sets the value automatically
{
    right_most_player = true;
}


bool Player::is_left_most_player()
{
    if (left_most_player == true)
        return true;
    else
        return false;
}

bool Player::is_right_most_player()
{
    if (right_most_player == true)
        return true;
    else
        return false;
}