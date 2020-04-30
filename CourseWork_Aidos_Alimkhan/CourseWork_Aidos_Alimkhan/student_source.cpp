#include "student.h"

void student::student_register() {
	int inp;
	cout << "\tHello! Please, enter your student id:";
	cin >> student_id;
	cout << "\nEnter your name and surname:";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nYour gender:";
	cout << "\n 1.Male   | 2.Female\n";
	cin >> inp;
	switch (inp) {
	case 1:strcpy_s(gender, "male"); break;
	case 2:strcpy_s(gender, "female"); break;
	}
	cout << "\nEnter your nationality:";
	cin.ignore();
	cin.getline(nationality, 30);
	cout << "\nPlease, choose one of these options:";
	cout << "\n1.I am full-time student.";
	cout << "\n2.I am exchange student.\n";
	cin >> inp;
	switch (inp) {
	case 1: cout << "\nAs you are full-time student, you will live in Dormitory N.1\n";
		strcpy_s(type_of_student, "full-time");
		strcpy_s(address, "Sauletekio 25");
		num_of_dorm = 1;
		break;
	case 2: cout << "\nAs you are exchange student, you will live in Dormitory N.2\n";
		strcpy_s(type_of_student, "exchange");
		strcpy_s(address, "Sauletekio 39");
		num_of_dorm = 2; break;
	}

}

void student::show_resident() {
	cout << "Resident ID: " << student_id;
	cout << "\nName of resident: " << name;
	cout << "\nGender: " << gender;
	cout << "\nNationality:  " << nationality;
	cout << "\nStudy type:  " << type_of_student;
	cout << "\nDormitory: Bendrabutis N." << num_of_dorm;
	cout << "\nRoom number:  " << room_num;
	cout << "\nRoom type:  " << room_type;
	cout << "\nYou pay " << room_cost << " euro for this room";
	cout << "\nAddress: " << address;
}

int student::id_ret(){
return student_id;
	}
student& student::operator=(const student& s) {
	strcpy_s(room_type, s.room_type);
	room_num = s.room_num;
	room_cost = s.room_cost;
	return *this;
}