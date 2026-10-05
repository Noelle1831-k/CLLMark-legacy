void MeetingRecorder::saveMeetingDetails() {
    ofstream file("meeting_details.txt");
    if (file.is_open()) {
        file << "Meeting Title: " << meetingTitle << endl;
        file << "Attendees: ";
        for (size_t i = 0; i < attendees.size(); i++) {
            file << attendees[i];
            if (i < attendees.size() - 1) file << ", ";
        }
        file << endl;
        file << "Agenda: ";
        for (size_t i = 0; i < agenda.size(); i++) {
            file << agenda[i];
            if (i < agenda.size() - 1) file << ", ";
        }
        file << endl;
        file << "Discussion Points: ";
        for (size_t i = 0; i < discussionPoints.size(); i++) {
            file << discussionPoints[i];
            if (i < discussionPoints.size() - 1) file << ", ";
        }
        file << endl;
        file.close();
        cout << "Meeting details saved successfully." << endl;
    } else {
        cout << "Error: Unable to save meeting details." << endl;
    }
}