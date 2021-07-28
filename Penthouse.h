#include "Room.h"
#ifndef PENTHOUSE_H
#define PENTHOUSE_H

class Penthouse : public Room {
private:
    static int pRoom_available;
public:
    Penthouse() {
        pRoom_available -= 1;
        total_room_booked += 1;
        total_revenue += 1135;
    }
    int get_pRoom_available() const {
        return pRoom_available;
    }
};
int Penthouse::pRoom_available = 2;

#endif
