void SystemManager::manageSessions() {
    int choice;
    cout << "\nSession Management:\n1. Create Session\n2. Update Session\n3. Cancel Session\n4. List Sessions\nEnter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1: {
            string tutorName, learnerName, subject, time;
            cout << "Enter tutor name: ";
            cin >> tutorName;
            cout << "Enter learner name: ";
            cin >> learnerName;
            cout << "Enter subject: ";
            cin >> subject;
            cout << "Enter time: ";
            cin >> time;
            User* tutor = nullptr;
            User* learner = nullptr;
            for (int i = 0; i < users.size(); i++) {
                if (users[i]->getName() == tutorName && users[i]->getRole() == "tutor") {
                    tutor = users[i];
                }
                if (users[i]->getName() == learnerName && users[i]->getRole() == "learner") {
                    learner = users[i];
                }
            }
            if (tutor && learner) {
                Session newSession(tutor, learner, subject, time);
                sessions.push_back(newSession);
                cout << "Session created successfully." << endl;
            } else {
                cout << "Tutor or learner not found. Session not created." << endl;
            }
            break;
        }
        case 2: {
            int sessionId;
            string newTime;
            cout << "Enter session ID to update: ";
            cin >> sessionId;
            cout << "Enter new time: ";
            cin >> newTime;
            for (int i = 0; i < sessions.size(); i++) {
                if (sessions[i].getSessionId() == sessionId) {
                    sessions[i].updateSession(newTime);
                    break;
                }
            }
            break;
        }
        case 3: {
            int sessionId;
            cout << "Enter session ID to cancel: ";
            cin >> sessionId;
            for (int i = 0; i < sessions.size(); i++) {
                if (sessions[i].getSessionId() == sessionId) {
                    sessions[i].cancelSession();
                    break;
                }
            }
            break;
        }
        case 4:
            listSessions();
            break;
        default:
            cout << "Invalid choice." << endl;
    }
}