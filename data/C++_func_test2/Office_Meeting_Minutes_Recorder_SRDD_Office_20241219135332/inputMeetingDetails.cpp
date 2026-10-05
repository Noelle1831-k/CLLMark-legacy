void MeetingRecorder::inputMeetingDetails() {
    cout << "Enter meeting title: ";
    getline(cin, meetingTitle);
    cout << "Enter attendees (comma-separated): ";
    string attendeeInput;
    getline(cin, attendeeInput);
    size_t pos = 0;
    while ((pos = attendeeInput.find(',')) != string::npos) {
        attendees.push_back(attendeeInput.substr(0, pos));
        attendeeInput.erase(0, pos + 1);
    }
    attendees.push_back(attendeeInput);
    cout << "Enter agenda items (comma-separated): ";
    string agendaInput;
    getline(cin, agendaInput);
    pos = 0;
    while ((pos = agendaInput.find(',')) != string::npos) {
        agenda.push_back(agendaInput.substr(0, pos));
        agendaInput.erase(0, pos + 1);
    }
    agenda.push_back(agendaInput);
    cout << "Enter discussion points (comma-separated): ";
    string discussionInput;
    getline(cin, discussionInput);
    pos = 0;
    while ((pos = discussionInput.find(',')) != string::npos) {
        discussionPoints.push_back(discussionInput.substr(0, pos));
        discussionInput.erase(0, pos + 1);
    }
    discussionPoints.push_back(discussionInput);
}