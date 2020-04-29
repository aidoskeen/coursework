#pragma once
#include <iostream>
using namespace std;
class room {
protected:
	int room_num;
	char room_type[10];
	int room_cost;
public:
	room() {
		room_num = 0;
		strcpy_s(room_type, "N/A");
		room_cost = 110;
	}
	room(const char* type, int cost) {
		strcpy_s(room_type, type);
		room_cost = cost;
	}
	room(int roomn, const char* type, int cost) {
		strcpy_s(room_type, type); 
		room_cost = cost;
		room_num = roomn;
	}
	friend ostream& operator<<(ostream& out, const room& r); 
	
	int ret_room();
};