void MeetingRoom::bookRoom(string startTime, string endTime) {
    if (isAvailable(startTime, endTime)) {
        bookedSlots.push_back(make_pair(startTime, endTime));
    }
}