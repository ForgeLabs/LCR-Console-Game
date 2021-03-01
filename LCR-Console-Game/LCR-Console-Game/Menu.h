#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "DataBaseManager.h"
#include "Player.h"
#include "ValidName.h"
#include "PlayerGroup.h"
#include "Die.h"
#include "LCR.h"
#include <ctime>
#include <mysql.h>

class Menu {

public:
	Menu();

	void print_menu();
	void manage_menu();

};

#endif