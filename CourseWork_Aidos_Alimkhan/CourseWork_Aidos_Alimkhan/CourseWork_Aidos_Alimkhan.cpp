#include <iostream>

using namespace std;


class room {
protected:
	int room_num;
	char room_type[10];
	int room_cost;
};
class student {
protected:
	char name[50];
	char gender[30];
	char nationality[30];
	char type_of_student[20];
	int num_of_contract;
public:
	student(){
		strcpy_s(name, "N/A");
		strcpy_s(gender, "N/A");
		strcpy_s(nationality, "N/A");
		strcpy_s(type_of_student, "N/A");
		num_of_contract = 0;
		
	}
	void show();
	
};
void student::show() {
	cout << gender;
}
class dormitory :protected room, public student {

	int num_of_rooms;
	int num_of_dorm;
	char address[30];
public:
	void student_register();
	
};
void dormitory::student_register() {
	int inp;
	cout << "Hello! Enter number of contract with VGTU:";
	cin >> num_of_contract;
	cout << "\nEnter your name and surname:";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nYour gender:";
	cout << "\n 1.Male   | 2.Female";
	cin >> inp;
	switch (inp) {
	case 1:strcpy(gender,"male") ; break;
	case 2:strcpy(gender, "female"); break;
	}
	cout << "\nEnter your nationality:";
	cin.ignore();
	cin.getline(nationality, 30);
	cout << "Please, choose one of these options:";
	cout << "\n1.I am full-time student.";
	cout << "\n2.I am exchange student.";
	cin >> inp;
	switch (inp) {
	case 1: cout<<"\nAs you are full-time student, you will live in Dormitory N.1"; 
		strcpy(type_of_student, "full-time");
		strcpy(address, "Sauletekio 25");
		num_of_dorm = 1;
		break;
	case 2: cout << "\nAs you are exchange student, you will live in Dormitory N.2"; 
		strcpy(type_of_student, "exchange");
		strcpy(address, "Sauletekio 39");
		num_of_dorm = 2; break;
	}
	cout << "\nPlease, choose type of room:";
	cout << "\n1.Single Person room. Cost is 150 euro.";
	cout << "\n2.Room for 2 people. Cost is 110 euro.";
	cin >> inp;
	switch (inp)
	{
	case 1:strcpy(room_type, "Single"); room_cost = 150;
		cout << "\nChoose your room number(1-50)"; break;
	case 2:strcpy(room_type, "Double"); room_cost = 110; break;
	}
	
	
}

class service {
	char day[10];
	char service_type[20];
	char problem[20];
	int problem_id;
};

int main() {

}

