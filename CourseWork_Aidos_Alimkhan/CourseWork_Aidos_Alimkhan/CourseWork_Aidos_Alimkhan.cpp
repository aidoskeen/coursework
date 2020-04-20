#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

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

};

class student {
protected:
	char name[50];
	char gender[30];
	char nationality[30];
	char type_of_student[20];
	int student_id;
public:
	student(){
		strcpy_s(name, "N/A");
		strcpy_s(gender, "N/A");
		strcpy_s(nationality, "N/A");
		strcpy_s(type_of_student, "N/A");
		student_id = 0;
		
	}
	
	
};

class dormitory :protected room, protected student {
protected:
	int num_of_rooms;
	int num_of_dorm;
	char address[30];
public:
	dormitory() {
		num_of_rooms = 0;
		num_of_dorm = 0;
		strcpy_s(address, "unknown");
	}
	void student_register();
	void show_resident();
	int id_ret() {
		return student_id;
	}
	
};
void dormitory::student_register() {
	int inp;
	cout << "Hello! Please, enter your student id:";
	cin >> student_id;
	cout << "\nEnter your name and surname:";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nYour gender:";
	cout << "\n 1.Male   | 2.Female";
	cin >> inp;
	switch (inp) {
	case 1:strcpy_s(gender,"male") ; break;
	case 2:strcpy_s(gender, "female"); break;
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
		strcpy_s(type_of_student, "full-time");
		strcpy_s(address, "Sauletekio 25");
		num_of_dorm = 1;
		break;
	case 2: cout << "\nAs you are exchange student, you will live in Dormitory N.2"; 
		strcpy_s(type_of_student, "exchange");
		strcpy_s(address, "Sauletekio 39");
		num_of_dorm = 2; break;
	}
	cout << "\nPlease, choose type of room:";
	cout << "\n1.Single Person room. Cost is 150 euro.";
	cout << "\n2.Room for 2 people. Cost is 110 euro.";
	cin >> inp;
	switch (inp)
	{
	case 1:strcpy_s(room_type, "Single"); room_cost = 150;
		cout << "\nChoose your room number(1,11,21,31,41)";
		cin >> room_num;
		while (room_num != 1 || room_num != 11 || room_num != 21 || room_num != 31 || room_num != 41) {
			cout << "\nYour entered invalid room number. Enter correct room number:";
			cin >> room_num;
		}
		break;
	case 2:strcpy_s(room_type, "Double"); room_cost = 110;
		cout << "\Choose your room number\n1st floor:2-10 \n2nd floor:12-20;\n3rd floor: 22-30 \n4th floor: 32-40; \n5th floor 42-50";
		cin >> room_num;
		while (room_num < 2 || room_num>50 || room_num ==11 || room_num ==21 || room_num == 31 || room_num ==41) {
			cout << "\nYou entered invalid room number. Enter coorect room number";
			cin >> room_num;
		}
		 break;
	default:break;
	}
}
void dormitory::show_resident() {
	cout << "Resident ID: " << student_id;
	cout << "\nName of resident: " << name;
	cout << "\nGender: " << gender;
	cout << "\nNationality:" << nationality;
	cout << "\nStudy type:" << type_of_student;
	cout << "\nDormitory: Bendrabutis N." << num_of_dorm;
	cout << "Room number:" << room_num;
	cout << "\nRoom type:" << room_type;
	cout << "\nYou pay " << room_cost << " euro for this room";
	cout <<"\n"<< address;
}


class service:protected dormitory{
	char day[10];
	char service_type[20];
	char problem[100];
	int problem_id;
public:
	service() {
		strcpy_s(day, "Monday");
		strcpy_s(service_type, "Not selected");
		strcpy_s(problem, "No problem");
		problem_id = 0;
	}
	void service_info();
	void problem_info();
	int ret_probID();
	void show_service();
};
void service::service_info() {
	int n;
	cout << "Number of your Dormitory:";
	cin >> num_of_dorm;
	cout << "Enter your room number:";
	cin >> room_num;
	cout << "Choose what do you need:";
	cout << "1. Room cleaning";
	cout << "2. Request new laundry";
	cin >> n;
	
	switch (n)
	{
	case 1:strcpy_s(service_type, "Cleaning"); cout << "When you want to your room be cleaned?"; break;
	case 2:strcpy_s(service_type, "Laundry"); cout << "When you want new laundry?"; break;
	default:return; break;
	}
	srand((int)time(0));
	problem_id = (rand() % 1000) + 1;
	cin >> n;
	cout << "\nMonday";
	cout << "\nTuesday";
	cout << "\nWednesday";
	cout << "\nThursday";
	cout << "\nFriday";
	switch (n) {
	case 1:strcpy_s(day, "Monday"); break;
	case 2:strcpy_s(day, "Tuesday"); break;
	case 3:strcpy_s(day, "Wednesday"); break;
	case 4:strcpy_s(day, "Thursday"); break;
	case 5:strcpy_s(day, "Friday"); break;
	default:return; break;
	}
}

void service::problem_info() {
	cout << "Number of your Dormitory:";
	cin >> num_of_dorm;
	cout << "\nEnter your room number:";
	cin >> room_num;
	cout << "\nPlease, explain your problem in two-three words(need to fix the door, fix the shower, problem with internet etc.)";
	srand((int)time(0));
	problem_id = (rand() % 1000) + 1;
	cin.ignore();
	cin.getline(problem, 100);
}
int service::ret_probID() {
	return problem_id;
}
void service::show_service() {
	cout << setw(10) << problem_id << setw(10) << service_type << setw(10) << day << endl;
}





void main_menu();

void get_place() {
	system("cls");
	fstream file;
	dormitory d;
	file.open("dormitory.dat", ios::out | ios::app);
	d.student_register();
	file.write((char*)&d, sizeof(dormitory));
	file.close();
	cout << "\nYour place in dormitory successfully reserved. \nPlease, bring your ID with you when you get to the dormitory.";
	cin.ignore();
	main_menu();
}
void show_info() {
	system("cls");
	int n;
	cout << "Enter your id: ";
	cin >> n;
	
	dormitory d;
	student s;
	fstream file;
	bool flag = false;
	cout << "\nInformation about resident.";
	
	file.open("dormitory.dat", ios::in);
	while (file.read((char*)&d, sizeof(dormitory)))
	{
		if (d.id_ret()==n)
		{
				d.show_resident();
			flag = true;
		}
	}

	file.close();
	if (flag == false) {
		cout << "\nSorry, there is no such resident. Do you want to register and get a place? If yes type 'y'; If no type n";
		char yn;
		cin >> yn;
		switch (yn)
		{
		case 'y':
		case 'Y':get_place(); break;
		case 'n':
		case'N':main_menu(); break;
		default:
			cout << "\nInvalid input. You will be directed to main menu"; cin.ignore(); main_menu(); break;
		}
	
	}
}
void correct_data()
{
	dormitory d;
	fstream file;
	int n, found = 0;
	system("cls");
	cout << "\n\n\tCorrection ";
	cout << "\nPlease enter id of student";
	cin >> n;
	file.open("dormitory.dat", ios::in | ios::out);
	while (file.read((char*)&d, sizeof(dormitory)) && found == 0)
	{
		if (d.id_ret() == n)
		{
			d.show_resident();
			cout << "\nPlease Enter new data:" << endl;
			d.student_register();
			int pos = -1 * static_cast<int>(sizeof(d));
			file.seekp(pos, ios::cur);
			file.write((char*)&d, sizeof(dormitory));
			cout << "\n\n\t Updated";
			found = 1;
		}
	}
	file.close();
	if (found == 0)
		cout << "\n\n  Not Found ";
	cin.ignore();
}


void main_menu() {
	int inp;;
	cout << "\tMAIN MENU";
	cout << "\n\tServices";
	cout << "\n\tMy info";
	cout << "\n\tGet a room in the dormitory";
	cin >> inp;
	switch (inp)
	{
	case 1:
	case 2:show_info(); break;
	case 3: get_place(); break;

	default:
		break;
	}
}
void services() {
	system("cls");
	fstream file;
	int n;
	service s;
	file.open("service.dat", ios::out | ios::app);
	cout << "Service";
	cout << "Report an issue";
	cin >> n;
	switch (n)
	{
	case 1:	s.service_info();
		if (s.ret_probID() != 0) {
			file.write((char*)&s, sizeof(service));
			cout << "\nYour request is accepted.";
		}
		else {
			cout << "\nYou entered invalid data.Please Try again.";
			return;
		}
		break;
	case 2:s.problem_info();
		if (s.ret_probID() != 0) {
			file.write((char*)&s, sizeof(service));
			cout << "\nYour report is sent to administration. It will be reviewed soon.";
		}
		else {
			cout << "\nYou entered invalid data.Please Try again.";
			return;
		}
		break;
	default:
		return; break;
	}
	
	file.close();
	cin.ignore();
	main_menu();
}


int main() {
	main_menu();
}


