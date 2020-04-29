#pragma once
#include <iostream>
using namespace std;
class dormitory { 
protected:
	int num_of_rooms;
	int num_of_dorm;
	char address[30];
public:
	dormitory() {
		num_of_rooms = 50;
		num_of_dorm = 0;
		strcpy_s(address, "unknown");
	}
	dormitory(const char* address, int num, int rooms_number) {
		strcpy_s(this->address, address);
		num_of_dorm = num;
		num_of_rooms = rooms_number;
	}
	void display_data();
};