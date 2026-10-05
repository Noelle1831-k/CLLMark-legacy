void MeetingRecorder::loadMeetingDetails() {
    ifstream file("meeting_details.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No meeting details found." << endl;
    }
}