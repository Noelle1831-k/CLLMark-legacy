bool MeetingSchedule::addMeeting(string startTime, string endTime) {
    if (isTimeSlotAvailable(startTime, endTime)) {
        meetings.push_back(make_pair(startTime, endTime));
        return true;
    }
    return false;
}