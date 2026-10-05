void displaySchedule() const {
        cout << "Events:" << endl;
        for (vector<Event>::const_iterator it = events.begin(); it != events.end(); ++it) {
            cout << it->getDetails() << endl;
        }
        cout << "Tasks:" << endl;
        for (vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
            cout << it->getDetails() << endl;
        }
    }