#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() {
	MYSQL* connection;
	MYSQL_ROW row;
	MYSQL_RES* res;
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "database", 3306, NULL, 0);
	table_name = "null";
}

MYSQL* DatabaseManager::get_connection() {
	return connection;
}

void DatabaseManager::set_table_name(std::string s) {
	table_name = s;
}

std::string DatabaseManager::get_table_name() {
	return table_name;
}

void DatabaseManager::insert_into_table(std::string p_name, int curr_score, char d_face, int new_score, bool b) {
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "database", 3306, NULL, 0);

	std::string b_alpha = "false";
	if (b == true)
		b_alpha = "true";
	else
		b_alpha = "false";

	std::string query = "INSERT INTO " + get_table_name();
	query += " (player, curr_score, die_face, new_score, winner) VALUES (""\"" + p_name + "\", " + std::to_string(curr_score) + ", ""\"" + d_face + """\", " + std::to_string(new_score) + ", " + b_alpha + ");";
	const char* q = query.c_str();

	mysql_query(connection, q);
}

void DatabaseManager::read_table() {
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "database", 3306, NULL, 0);
	std::string query = "SELECT * FROM " + get_table_name();
	const char* q = query.c_str();
	mysql_query(connection, q);
	res = mysql_store_result(connection);

	while (row = mysql_fetch_row(res)) {
		//Loop each six columns of each row and print
		for (int i = 0; i < 6; i++)
			std::cout << row[i] << ": ";
		std::cout << std::endl;
	}
}

void DatabaseManager::create_table() {

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter the game name:" << std::endl;

	ValidName temp_name;
	std::string clean_name = temp_name.get_valid_name();

	set_table_name(clean_name);

	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "password", "database", 3306, NULL, 0);
	std::string query = "CREATE TABLE " + get_table_name();
	query += " (round_num int(255) PRIMARY KEY AUTO_INCREMENT, player varchar(25) NOT NULL, curr_score int(1) NOT NULL, die_face varchar(1) NOT NULL, new_score int(1) NOT NULL, winner boolean NOT NULL);";
	const char* q = query.c_str();
	mysql_query(connection, q);
}

MYSQL_ROW DatabaseManager::get_row() {
	return row;
}

MYSQL_RES* DatabaseManager::get_res() {
	return res;
}
