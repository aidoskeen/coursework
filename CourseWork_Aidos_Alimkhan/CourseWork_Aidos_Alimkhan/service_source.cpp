#include "services.h"
void service::service_info() {
	int n;
	cout << "\nNumber of your Dormitory:(1/2)\n";
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
	cout << "\nFriday<5>\n";
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
	cout << endl << setw(10) << problem_id << setw(20) << service_type << setw(15) << problem << setw(10) << room_num << setw(7) << num_of_dorm << setw(10) << day << endl;
}