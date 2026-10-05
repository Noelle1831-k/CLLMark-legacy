bool MeetingRoom::isAvailable(string startTime, string endTime) {
    for (size_t i = 0; i < bookedSlots.size(); i++) {
        if (!(endTime <= bookedSlots[i].first || startTime >= bookedSlots[i].second)) {
            return false;
        }
    }
    return true;
}