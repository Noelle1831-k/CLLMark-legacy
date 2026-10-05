bool MeetingSchedule::isTimeSlotAvailable(string startTime, string endTime) {
    for (size_t i = 0; i < meetings.size(); i++) {
        if (!(endTime <= meetings[i].first || startTime >= meetings[i].second)) {
            return false;
        }
    }
    return true;
}