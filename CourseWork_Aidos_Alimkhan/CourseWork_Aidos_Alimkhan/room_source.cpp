#include "room.h"

int room::ret_room() {
	return room_num;
}
ostream& operator<<(ostream& out, const room& r) {
	out << "Room type:   " << r.room_type << "\nCost:  " << r.room_cost;
	return out;
}
