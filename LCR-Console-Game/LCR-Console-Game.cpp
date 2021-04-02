#include <mysql.h>
#include <iostream>
#include <string>

#include "DataBaseManager.h"
#include "Player.h"
#include "ValidName.h"
#include "PlayerGroup.h"
#include "Die.h"
#include "LCR.h"
#include "Menu.h"

int main()
{
	Menu main_menu;

	main_menu.manage_menu();

	return 0;
}


