void MeetingRoom::releaseRoom(string startTime, string endTime) {
    for (size_t i = 0; i < bookedSlots.size(); i++) {
        if (! (bookedSlots[i] != make_pair(startTime, endTime))) {
            bookedSlots.erase(bookedSlots.begin() + i);
            break;
        }
    }
}