#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {

public:

    Player();
    Player(std::string);

    std::string get_name();
    int get_place();
    int get_score();
    bool is_left_most_player();
    bool is_right_most_player();

    void set_score(int);
    void increase_score(int);
    void decrease_score(int);
    void set_place(int);
    void set_left_most();
    void set_right_most();
    void set_name(std::string&);

private:
    bool left_most_player;
    bool right_most_player;
    std::string name;
    int score;
    int place; //goes by PlayerGroup location in the vector, not the player's score

};

#endif