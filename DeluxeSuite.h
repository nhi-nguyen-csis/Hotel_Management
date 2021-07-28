#include "Room.h"
#ifndef DELUXESUITE_H
#define DELUXESUITE_H

class DeluxeSuite : public Room {
private:
    static int dRoom_available;
public:
    DeluxeSuite() {
        dRoom_available -= 1;
        total_room_booked += 1;
        total_revenue += 350;
    }
    int get_dRoom_available() const {
        return dRoom_available;
    }
};
int DeluxeSuite::dRoom_available = 15;

#endif