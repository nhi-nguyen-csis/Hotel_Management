#include "Room.h"
#ifndef COURTYARD_H
#define COURTYARD_H

class Courtyard : public Room {
private:
    static int cRoom_available;
    int cRoom_booked;
public:
    Courtyard() {
        cRoom_available -= 1;
        total_room_booked += 1;
        total_revenue += 125;
    }
    int get_cRoom_available() const {
        return cRoom_available;
    }
};
//define static variable cRoom_available
int Courtyard::cRoom_available = 70;

#endif
