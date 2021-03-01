#include "Menu.h"

Menu::Menu() {}

void Menu::print_menu() {

	std::cout << "+=================================+\n"
		<< "| Welcome to LCR, please select   |\n"
		<< "| an option:                      |\n"
		<< "+=================================+\n"
		<< "| Play Game (P)                   |\n"
		<< "+=================================+\n"
		<< "| View Scores (S)                 |\n"
		<< "+=================================+\n"
		<< "| Exit (E)                        |\n"
		<< "+=================================+\n";
}


/// <summary>
/// Menu system loops through till a valid selection is made
/// Menu exits only upon the exit key
/// Once game is finished, return to the main menu
/// </summary>
void Menu::manage_menu() {
	LCR gameplay;

	char input = '0';

	do
	{
		print_menu();
		std::cin >> input;
		switch (input)
		{
		case 'P':
			system("cls");
			gameplay.play_game();
			break;
		case 'S':
			system("cls");
			std::cout << "You chose S!" << std::endl;
			break;
		case 'E':
			system("cls");
			std::cout << "Goodbye!" << std::endl;
			std::exit;
			break;
		default:
			system("cls");
			break;
		}
	} while (input != 'E');
}