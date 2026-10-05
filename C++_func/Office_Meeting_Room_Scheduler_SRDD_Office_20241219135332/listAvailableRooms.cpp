void Scheduler::listAvailableRooms() {
    for (size_t i = 0; i < rooms.size(); i++) {
        if (rooms[i].isAvailable("00:00", "23:59")) { 
            cout << "Room ID: " << rooms[i].getRoomId() << ", Capacity: " << rooms[i].getCapacity() << endl;
        }
    }
}