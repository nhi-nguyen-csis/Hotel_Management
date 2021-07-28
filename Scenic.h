#include "Room.h"
#ifndef SCENIC_H
#define SCENIC_H

class Scenic : public Room {
private:
    static int sRoom_available;
public:
    Scenic() {
        sRoom_available -= 1;
        total_room_booked += 1;
        total_revenue += 145;
    }
    int get_sRoom_available() const {
        return sRoom_available;
    }
};
int Scenic::sRoom_available = 35;

#endif
