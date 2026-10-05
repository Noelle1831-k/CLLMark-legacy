void MeetingScheduler::addMeeting() {
    string title, date, time;
    int duration;
    cout << "Enter meeting title: ";
    cin >> title;
    cout << "Enter meeting date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter meeting time (HH:MM): ";
    cin >> time;
    cout << "Enter meeting duration (in minutes): ";
    cin >> duration;
    Meeting meeting(title, date, time, duration);
    meetings.push_back(meeting);
    cout << "Meeting added successfully.\n";
}