void Scheduler::addRoom(int id, int capacity) {
    rooms.push_back(MeetingRoom(id, capacity));
    schedules.push_back(MeetingSchedule(id));
}