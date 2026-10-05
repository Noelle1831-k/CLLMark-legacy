void MeetingScheduler::displayAllMeetings() {
    if (meetings.empty()) {
        cout << "No meetings scheduled.\n";
        return;
    }
    for (int i = 0; i < (int)meetings.size(); ++i) {
        cout << "Meeting " << (i + 1) << ":\n";
        meetings[i].displayMeetingDetails();
    }
}