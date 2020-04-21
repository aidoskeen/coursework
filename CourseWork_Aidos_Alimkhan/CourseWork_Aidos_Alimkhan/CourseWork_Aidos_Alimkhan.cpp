#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h> 

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
	room(const char*type,int cost) {
		strcpy_s(room_type, type);
		room_cost = cost;
	}
	void display_data();
};
void room::display_data() {
	cout << "Room type:   " << room_type;
	cout << "Cost:  " << room_cost;
}
class dormitory  {
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
void dormitory::display_data() {
	cout << "\nBendrabutis N." << num_of_dorm;
	cout << "\nAddress:" << address;
	cout << "\nNumber of rooms:" << num_of_rooms;
}

class student :protected dormitory, protected room {
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
	void student_register();
	void show_resident();
	int id_ret() {
		return student_id;
	}
};
void student::student_register() {
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
			cout << "\n\aYour entered invalid room number. Enter correct room number:";
			cin >> room_num;
		}
		break;
	case 2:strcpy_s(room_type, "Double"); room_cost = 110;
		cout << "Choose your room number: \n1st floor:2-10 \n2nd floor:12-20;\n3rd floor: 22-30 \n4th floor: 32-40; \n5th floor 42-50";
		cin >> room_num;
		while (room_num < 2 || room_num>50 || room_num ==11 || room_num ==21 || room_num == 31 || room_num ==41) {
			cout << "\n\aYou entered invalid room number. Enter coorect room number";
			cin >> room_num;
		}
		 break;
	default:break;
	}
}
void student::show_resident() {
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


class service:protected room,protected dormitory{
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
	int id_ret();
	void display_data();
};
void service::service_info() {
	int n;
	cout << "\nNumber of your Dormitory:\n";
	cin >> num_of_dorm;
	cout << "\nEnter your room number:";
	cin >> room_num;
	cout << "\nChoose what do you need:";
	cout << "\n1. Room cleaning";
	cout << "\n2. Request new laundry\n";
	cin >> n;
	
	switch (n)
	{
	case 1:strcpy_s(service_type, "Cleaning"); cout << "\nWhen you want to your room be cleaned?"; break;
	case 2:strcpy_s(service_type, "Laundry"); cout << "\nWhen you want new laundry?\n"; break;
	default:return; break;
	}
	srand((int)time(0));
	problem_id = (rand() % 1000) + 1;
	
	cout << "\nMonday<1>";
	cout << "\nTuesday<2>";
	cout << "\nWednesday<3>";
	cout << "\nThursday<4>";
	cout << "\nFriday<5>";
	cin >> n;
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
	cout << "\nPlease, explain your problem in two-three words(need to fix the door, fix the shower, problem with internet etc.):";

	cin.ignore();
	cin.getline(problem, 100);
	srand((int)time(0));
	problem_id = (rand() % 1000) + 1;
}
int service::id_ret() {
	return problem_id;
}
void service::display_data() {
	cout << endl<<setw(10) << problem_id << setw(10) << service_type << setw(10)<<room_num<<setw(10)<<num_of_dorm<<setw(10) << day << endl;
}





void main_menu();

void get_place() {
	system("cls");
	fstream file;
	student s;
	file.open("dormitory.dat", ios::out | ios::app);
	s.student_register();
	file.write((char*)&s, sizeof(student));
	file.close();
	cout << "\nYour place in dormitory successfully reserved. \nPlease, bring your ID with you when you get to the dormitory.";
	(void)_getch();
	
	main_menu();
}
void show_info() {
	system("cls");
	int n;
	cout << "Enter your id: ";
	cin >> n;
	student s;
	fstream file;
	bool flag = false;
	cout << "\nInformation about resident.";
	
	file.open("dormitory.dat", ios::in);
	while (file.read((char*)&s, sizeof(student)))
	{
		if (s.id_ret()==n)
		{
				s.show_resident();
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
			cout << "\n\aInvalid input. You will be directed to main menu"; cin.ignore(); main_menu(); break;
		}
	
	}
	(void)_getch();
	main_menu();
}
void correct_data()
{
	student s;
	fstream file;
	int n, found = 0;
	system("cls");
	cout << "\n\n\tCorrection ";
	cout << "\nPlease enter id of student\n";
	cin >> n;
	file.open("dormitory.dat", ios::in | ios::out);
	while (file.read((char*)&s, sizeof(dormitory)) && found == 0)
	{
		if (s.id_ret() == n)
		{
			s.show_resident();
			cout << "\nPlease Enter new data:" << endl;
			s.student_register();
			int pos = -1 * static_cast<int>(sizeof(s));
			file.seekp(pos, ios::cur);
			file.write((char*)&s, sizeof(student));
			cout << "\n\n\t Updated";
			found = 1;
		}
	}
	file.close();
	if (found == 0)
		cout << "\n\n  Not Found ";
	cin.ignore();
}
void show_service() {
	service s;
	fstream file;
	file.open("service.dat", ios::in);
	cout << "Service id           Service     room   dorm   Time";
	while (file.read((char*)&s, sizeof(service)))
	{
		s.display_data();
	}
	file.close();
	(void)_getch();
	main_menu();
}

void services() {
	system("cls");
	fstream file;
	int n;
	service s;
	file.open("service.dat", ios::out | ios::app);
	cout << "\n\tService <1>";
	cout << "\n\tList <2>";
	cout << "\n\tReport an issue<3>";
	cout << "\n\tGo back <4>\n";
	cin >> n;
	switch (n)
	{
	case 1:	system("cls"); s.service_info();
		if (s.id_ret() != 0) {
			file.write((char*)&s, sizeof(service));
			cout << "\nYour request is accepted.";
		}
		else {
			cout << "\nYou entered invalid data.Please Try again.";
			return;
		}
		break;
	case 2:system("cls");show_service(); break;
	case 3:s.problem_info();
		if (s.id_ret() != 0) {
			file.write((char*)&s, sizeof(service));
			cout << "\nYour report is sent to administration. It will be reviewed soon.";
		}
		else {
			cout << "\nYou entered invalid data.Please Try again.";
			return;
		}
		break;
	case 4:main_menu();
	default:
		break;
	}
	
	file.close();
	_getch();
	main_menu();
}
void dorm_data() {
	int n;

	cout << "Please, choose dormitory in order to get information:\n";
	cout << "\nBendrabutis N.1 < 1 >";
	cout << "\nBendrabutis N.2 < 2 >";
	cin >> n;
	switch (n)
	{
	case 1: {dormitory d("Sauletekio 25", 1, 50); d.display_data();
		cout << "Do you want to see address on map?If yes type 1";
		cin >> n;
		if (n == 1) {
			char url[100] = "https://bit.ly/2XTuBoD";
			ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
		}
		break;
	}
	case 2: {dormitory dor("Sauletekio 39", 2, 50); dor.display_data();
		cout << "Do you want to see address on map?If yes type 1";
		cin >> n;
		if (n == 1) {
			char url[100] = "https://bit.ly/2VqWVgt";
			ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
		}
		break;
	}
	default:break;
	}
	cin.ignore();
	main_menu();
}
void room_info() {
	int n;
	cout << "Here you can find information about rooms.";
	cout << "\nPlease, choose type of room you want to get information about:";
	cout << "<1> Single-bed <1>";
	cout << "\n<2> Double-bed <2>";
	cin >> n;
	switch (n) {
	case 1: {
		system("cls");
		room r("Single", 150); r.display_data();
		cout << "\n\tSingle rooms are specially built for students who prefer live alone and feel comfortable in silence.\n\tThey have all basic furniture: 1 bed, 1 cupboard, 1 table,1 chair and a fridge.";
		cout << "\nDo you want to see photo of room?(1,2)";
		cin >> n;
		if (n == 1) {
			char file[50] = ("image1.jpg"); ShellExecute(0, "open", file, NULL, NULL, SW_NORMAL);
		}
		break;
	}
	case 2: {
		system("cls");
		room r("Double", 110); r.display_data();
		cout << "\n\tDouble rooms are built for 2 people.\n\tThey have all basic furniture: 2 beds, 1 cupboard, 2 tables,2 chairs and a fridge.";
		cout << "\nDo you want to see photo of room?(1,2)";
		cin >> n;
		if (n == 1) {
			char file[50] = ("image2.jpg"); ShellExecute(0, "open", file, NULL, NULL, SW_NORMAL);
		}
		break;
	}
	}
	_getch();
	main_menu();
}
void main_menu() {
	system("cls");
	int inp;;
	cout << "\t\t\t         MAIN MENU\n";
	cout << "\n\t\t()           <1>  Service  <1>           () \n\t\t";
	cout << "\n\t\t()           <2>  My info  <2>           () \n\t\t";
	cout << "\n\t\t()  <3> Get a room in the dormitory <3>  () \n\t\t";
	cout << "\n\t\t()<4> See information about dormitory <4>() \n\t\t";
	cout << "\n\t\t() <5> See information about rooms <5>   () ";
	cin >> inp;
	switch (inp)
	{
	case 1: services(); break;
	case 2:show_info(); break;
	case 3: get_place(); break;
	case 4:dorm_data(); break;
	case 5: room_info(); break;
	default:
		break;
	}
}


int main() {
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\LOADING....\n\t";
	for (int i = 0; i < 50; i++) {
		Sleep(100);
		cout << "*";
}
	main_menu();
}


