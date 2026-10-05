void Meeting::displayMeetingDetails() {
    cout << "Title: " << title << "\n";
    cout << "Date: " << date << "\n";
    cout << "Time: " << time << "\n";
    cout << "Duration: " << duration << " minutes\n";
    if (participants.empty()) {
        cout << "No participants added.\n";
    } else {
        cout << "Participants:\n";
        for (int i = 0; i < (int)participants.size(); ++i) {
            participants[i].displayParticipantDetails();
        }
    }
}