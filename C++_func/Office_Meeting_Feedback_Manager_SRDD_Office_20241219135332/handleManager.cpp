void handleManager(vector<Meeting> &meetings) {
    cout << "Available Meetings:" << endl;
    for (size_t i = 0; i < meetings.size(); i++) {
        cout << i + 1 << ". " << meetings[i].getTitle() << endl;
    }
    int meetingChoice;
    cout << "Select a meeting to view feedback for: ";
    cin >> meetingChoice;
    if (meetingChoice < 1 || meetingChoice > meetings.size()) {
        cout << "Invalid meeting choice!" << endl;
        return;
    }
    Meeting &selectedMeeting = meetings[meetingChoice - 1];
    selectedMeeting.getFeedbackSummary();
}