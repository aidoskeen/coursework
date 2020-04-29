#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h> 
#include "room.h"
#include "dormitory.h"
#include "student.h"
#include "services.h"
using namespace std;


void main_menu();//function for creating main menu

void get_place() { // function for recording student's data to dormitory.dat file
	system("cls");
	fstream file;	//used for reading/writing operations with files
	fstream file2;
	student s;
	file.open("dormitory.dat", ios::out | ios::app);
	file2.open("dormitory.dat", ios::out | ios::app);
	s.student_register();
	
	int inp;
	cout << "\nPlease, choose type of room:";
	cout << "\n1.Single Person room. Cost is 150 euro.";
	cout << "\n2.Room for 2 people. Cost is 110 euro.\n";
	cin >> inp;
	switch (inp) {
	case 1: {int n;
		
		for(;;)//loop is used in order to insure uniqness of rooms
		{
			bool flag = false;
			srand((int)time(0)); //rooms are given randomly
			n = (rand() %5) + 1;
			while (file2.read((char*)&s, sizeof(student))) {//reading from a file
				if (s.ret_room() == n)//check whether this room already exist in file
				{
					flag = true;
				}
			}
			file2.close();
			if (flag == false) {
				student st(n, "single", 150);
				s = st;
				file.write((char*)&s, sizeof(student));//writing into file
				cout << "Your room is " << n;
				break;
			}
		}
		break;
	}
	case 2: {int n;
		for (;;)
		{
			int count = 0;
			srand((int)time(0));
			n = (rand() % 50) + 5;
			while (file2.read((char*)&s, sizeof(student))) {
				if (s.ret_room() == n)
				{
					count++;
				}
			}
			file2.close();
			if (count <= 2) {
				student st(n, "double", 110);
				s = st;
				file.write((char*)&s, sizeof(student));
				cout << "Your room is " << n;
				break;
			}
		}
		break;
	}
	}
   
	file.close();
	cout << "\nYour place in dormitory successfully reserved. \nPlease, bring your ID with you when you get to the dormitory.";
	cout << "\nPress ENTER to return to main menu..";
	(void)_getch();
	
	main_menu();
}
void correct_data()//function for changing the data within dat file
{
	student s;
	fstream file;
	int n;
	bool flag = false;
	system("cls");
	cout << "\n\n\tCorrection ";
	cout << "\nPlease enter id of student\n";
	cin >> n;
	file.open("dormitory.dat", ios::in | ios::out);
	while (file.read((char*)&s, sizeof(dormitory)) && flag == false)
	{
		if (s.id_ret() == n)
		{
			s.show_resident();
			cout << "\nPlease Enter new data:" << endl;
			s.student_register();
			int pos = -1 * static_cast<int>(sizeof(s));
			file.seekp(pos, ios::cur);//used for setting position
			file.write((char*)&s, sizeof(student));
			cout << "\n\n\t Data updated";
			flag = true;
		}
	}
	file.close();
	if (flag == false)
		cout << "\n\n  Not Found ";
	cout << "\nPress ENTER to return to main menu..";
	(void)_getch();
}

void show_info() {  //reads data from file and shows it
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
		cout << "\nSorry, there is no such resident. Do you want to register and get a place? \nIf yes type 'y'; \nIf no type n.\nInput: ";
		char yn;
		cin >> yn;
		switch (yn)
		{
		case 'y':
		case 'Y':get_place(); break;
		case 'n':
		case'N':main_menu(); break;
		default:
			cout << "\n\aInvalid input. You will be redirected to main menu"; (void)_getch(); main_menu(); break;
		}
	
	}
	cout << "\nIf some data is not proper,you can correct it.\nIf you want to do so, please type 1.\n If you want to go back to main menu type 2.\nYour choice: ";
	cin >> n;
	switch (n) {
	case 1:correct_data(); break;
	case 2: main_menu(); break;
	default:main_menu();
	}
	
}

void leave_dorm()//this function deletes record from dormitory.dat file
{

	student s;
	fstream file;
	fstream file_2;
	int n;
	bool flag = false;;
	system("cls");
	cout << "\tIt is so sad that you are going to leave dormitory. \nPlease enter your id:";
	cin >> n;
	file.open("dormitory.dat", ios::in | ios::out);

	file_2.open("dormitory1.dat", ios::out);
	file.seekg(0, ios::beg);
	while (file.read((char*)&s, sizeof(student)))
	{
		if (s.id_ret() != n) {
			file_2.write((char*)&s, sizeof(student));//records rewritten into new file
		}
		else { flag = true; }
	}


	file_2.close();
	file.close();
	char prev_name[] = "dormitory1.dat";
	char new_name[] = "dormitory.dat";
	remove(new_name);
	rename(prev_name, new_name); //renaming new file 
	if (flag)
		cout << "\n\n\tYou successfully logged out from dormitory system.";
	else
		cout << "\n\nSorry, your data cannot be found.";
	cout << "\nPress ENTER to return to main menu..";
	(void)_getch();
	main_menu();
}
void services();
void show_service() { //shows data from service.dat file
	service s;
	fstream file;
	file.open("service.dat", ios::in);
	cout << "Service id"<<setw(20)<<"Service"<<setw(13)<<"Problem"<<setw(12) <<"room"<<setw(8)<<"dorm" <<setw(9)<< "Time";
	while (file.read((char*)&s, sizeof(service)))
	{
		s.display_data();
		
	}
	file.close();
	cout << "Press ENTER..";
	(void)_getch();
	services();
}
void all_data()
{
	system("cls");
	student s;
	fstream file;
	file.open("dormitory.dat", ios::in);
	cout << "\n\n\t\tAll data about residents\n\n";
	while (file.read((char*)&s, sizeof(student)))
	{
		s.show_resident();
		cout << "\n\n******************************************\n";
	}
	file.close();
	cout << "\nPress ENTER to return to main menu..";
	(void)_getch();
	main_menu();
}

void services() { //services menu
	system("cls");
	fstream file;
	int n;
	service s;
	file.open("service.dat", ios::out | ios::app);
	cout << "\n\t\t\t\t          <1> Service <1>\n";
	cout << "\n\t\t\t\t       <2>List of issues <2>\n";
	cout << "\n\t\t\t\t       <3>Report an issue<3>\n";
	cout << "\n\t\t\t\t<4>See all data about residents<4>";
	cout << "\n\t\t\t\t  (Available only for personnel)\n";
	cout << "\n\t\t\t\t         <5>Go back <5>\nChoose number: ";
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
	case 2:system("cls"); show_service(); break;
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
	case 4: {
		string pass="password";
		string inp;
		cout << "Enter password:";
		cin >> inp;
		if (inp==pass)
			all_data();
		else
			cout << "Incorrect password.";
		break; }
	case 5:main_menu();
	default:
		break;
	}
	
	file.close();
	cout << "\nPress ENTER to return to main menu..";
	(void)_getch();
	main_menu();
}
void dorm_data() {//shows data about dormitory
	system("cls");
	int n;

	cout << "Please, choose dormitory in order to get information:\n";
	cout << "\n< 1 > Bendrabutis N.1 < 1 >";
	cout << "\n< 2 > Bendrabutis N.2 < 2 >\nYour input 1/2: ";
	cin >> n;
	switch (n)
	{
	case 1: {dormitory d("Sauletekio 25", 1, 50); d.display_data();
		cout << "\nDo you want to see address on map?\n\t<1> If YES type 1,\n\t <2> if NO type any number;\n Input: ";
		cin >> n;
		if (n == 1) {
			char url[100] = "https://bit.ly/2XTuBoD";
			ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);//opens browser
		}
		break;
	}
	case 2: {dormitory dor("Sauletekio 39", 2, 50); dor.display_data();
		cout << "\n Do you want to see address on map?If yes type 1\nInput: ";
		cin >> n;
		if (n == 1) {
			char url[100] = "https://bit.ly/2VqWVgt";
			ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
		}
		break;
	}
	default:break;
	}
	cout << "\nPress ENTER to return to main menu..";
	(void)_getch();
	main_menu();
}
void room_info() {//shows infor about room
	system("cls");
	int n;
	cout << "Here you can find information about rooms.";
	cout << "\nPlease, choose type of room you want to get information about:";
	cout << "\n\n\t<1> Single-bed <1>";
	cout << "\n\t<2> Double-bed <2>\n Select option 1/2: ";
	cin >> n;
	switch (n) {
	case 1: {
		system("cls");
		room r("Single", 150); cout<<r;
		cout << "\n\n\t-----------------------------------------------------------------------------";
		cout << "\n\tSingle rooms are specially built for students who prefer live alone and feel\n";
		cout<<"\tcomfortable in silence.\n\tThey have all basic furniture: 1 bed, 1 cupboard, 1 table,1 chair and a fridge.";
		cout << "\n\t-----------------------------------------------------------------------------";
		cout << "\n\tDo you want to see photo of room?\n\t<1> If YES, type 1;\n\t<2> if NO type 2: \nInput:  ";
		cin >> n;
		if (n == 1) {
			char file[50] = "image1.jpg"; ShellExecute(0, "open", file, NULL, NULL, SW_NORMAL);//opens picture
		}
		break;
	}
	case 2: {
		system("cls");
		room r("Double", 110); cout<<r;
		cout << "\n\n\t--------------------------------------------------------------------------------";
		cout << "\n\tDouble rooms are built for 2 people.\n\tThey have all basic furniture: 2 beds, 1 cupboard, 2 tables,2 chairs and a fridge.";
		cout << "\n\t----------------------------------------------------------------------------------";
		cout << "\n\tDo you want to see photo of room? \n\t<1> if YES, type 1; \n\t<2> if NO, any number: \nInput: ";
	
		cin >> n;
		if (n == 1) {
			char file[50] = "image2.jpg"; ShellExecute(0, "open", file, NULL, NULL, SW_NORMAL);
		}
		break;
	}
	}
	cout << "\nPress ENTER to return to main menu..";
	(void)_getch();
	main_menu();
}


void main_menu() {
	system("cls");
	int inp;;
	cout << "\t\t\t\t\t         MAIN MENU\n";
	cout << "\n\t\t\t\t<1> See information about dormitory <1> \n";
	cout << "\n\t\t\t\t  <2> See information about rooms <2>   \n";
	cout << "\n\t\t\t\t  <3> Get a room in the dormitory <3>  \n";
	cout << "\n\t\t\t\t           <4>  Services <4>           \n";
	cout << "\n\t\t\t\t           <5>  My info  <5>          \n";
	cout << "\n\t\t\t\t      <6> Leave the dormitory <6>      \n";
	cout << "\n\t\t\t\t             <7>  QUIT  <7>             ";
	cout << "\n\t\tSelect one option:";

	cin >> inp;
	switch (inp)
	{
	case 1:dorm_data(); break;
	case 2: room_info(); break;
	case 3: get_place(); break;
	case 4: services(); break;
	case 5:show_info(); break;
	case 6:leave_dorm(); break;
	case 7: EXIT_SUCCESS;
	default:
		break;
	}
}


int main() {
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\tLOADING....\n\t";
	for (int i = 0; i < 100; i++) { 
		Sleep(10);//used for output with delay
		cout << "*";
}
	main_menu();
}


