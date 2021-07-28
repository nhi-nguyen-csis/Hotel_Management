#ifndef ROOM_H
#define ROOM_H

class Room {
protected:
    static int total_revenue;
    static int total_room_booked;
public:
    int get_total_room_booked() const {
        return total_room_booked;
    }
    int get_total_revenue() const {
        return total_revenue;
    }
};

int Room::total_revenue = 0;
int Room::total_room_booked = 0;

#endif
