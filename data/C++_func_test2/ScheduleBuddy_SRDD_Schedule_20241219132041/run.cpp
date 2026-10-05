void UserInterface::run() {
    int choice;
    do {
        cout << "1. Add Event" << endl;
        cout << "2. Remove Event" << endl;
        cout << "3. Display All Events" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            string name, date, time, description;
            cout << "Enter event name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter event date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter event time (HH:MM): ";
            getline(cin, time);
            cout << "Enter description: ";
            getline(cin, description);
            scheduler.addEvent(Event(name, date, time, description));
        } else if (choice == 2) {
            string name;
            cout << "Enter event name to remove: ";
            cin.ignore();
            getline(cin, name);
            if (scheduler.removeEvent(name)) {
                cout << "Event removed successfully." << endl;
            } else {
                cout << "Event not found." << endl;
            }
        } else if (choice == 3) {
            scheduler.displayAllEvents();
        } else if (choice != 4) {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);
}