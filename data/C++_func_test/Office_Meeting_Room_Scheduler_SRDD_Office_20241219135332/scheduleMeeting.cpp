bool Scheduler::scheduleMeeting(int roomId, string startTime, string endTime) {
    for (size_t i = 0; i < rooms.size(); i++) {
        if (rooms[i].getRoomId() == roomId) {
            if (rooms[i].isAvailable(startTime, endTime) && schedules[i].addMeeting(startTime, endTime)) {
                rooms[i].bookRoom(startTime, endTime);
                return true;
            }
        }
    }
    return false;
}