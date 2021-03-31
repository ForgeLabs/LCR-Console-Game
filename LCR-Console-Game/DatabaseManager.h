#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "ValidName.h"
#include <iostream>
#include <string>
#include <sstream>
#include <mysql.h>
#include <climits>
#undef max

class DatabaseManager {

public:

	DatabaseManager();

	std::string get_table_name();
	MYSQL* get_connection();
	MYSQL_ROW get_row();
	MYSQL_RES* get_res();

	//Functions for CRUD
	void set_table_name(std::string);
	void insert_into_table(std::string, int, char, int, bool);
	void read_table();
	void create_table();

private:

	/// <summary>
	/// Creates SQL connection to port 3306
	/// on localhost - note, MySql must already
	/// be running on this port
	/// </summary>
	MYSQL* connection;
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string table_name;
};

#endif 