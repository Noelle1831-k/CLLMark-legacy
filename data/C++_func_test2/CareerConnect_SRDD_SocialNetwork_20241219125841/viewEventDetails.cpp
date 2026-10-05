void viewEventDetails() {
        cout << "Event ID: " << eventID << "\nEvent Name: " << eventName << "\nEvent Date: " << eventDate << "\nParticipants: ";
        for (vector<string>::iterator it = participants.begin(); it != participants.end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
    }