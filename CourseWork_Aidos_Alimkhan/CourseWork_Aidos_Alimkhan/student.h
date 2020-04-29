#pragma once
#include "dormitory.h"
#include "room.h"
#include <iostream>
using namespace std;
class student :protected dormitory, public room { //class student which inherits from dormitory and room
protected:
	char name[50];
	char gender[30];
	char nationality[30];
	char type_of_student[20];
	int student_id;
public:
	student() {
		strcpy_s(name, "N/A");
		strcpy_s(gender, "N/A");
		strcpy_s(nationality, "N/A");
		strcpy_s(type_of_student, "N/A");
		student_id = 0;

	}
	student(int roomn, const char* type, int cost) {
		strcpy_s(room_type, type);
		room_cost = cost;
		room_num = roomn;
	}
	student& operator=(const student& s);
	void student_register();
	void show_resident();
	int id_ret();
};