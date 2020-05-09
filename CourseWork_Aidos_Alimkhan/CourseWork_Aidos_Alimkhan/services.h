#pragma once
#include "dormitory.h"
#include "room.h"
#include <iostream>
#include <iomanip>
using namespace std;
class service :protected room, protected dormitory {
	char day[10];
	char service_type[20];
	char problem[100];
	int problem_id;
public:
	service() {
		strcpy_s(day, "Monday");
		strcpy_s(service_type, "Repair");
		strcpy_s(problem, "Service");
		problem_id = 0;
	}
	void service_info();
	void problem_info();
	int id_ret();
	void display_data();

};