int main() {
    EventManager eventManager;
    int choice;
    while (true) {
        cout << "\n--- Office Event RSVP Tracker ---\n";
        cout << "1. Create Event\n";
        cout << "2. List Events\n";
        cout << "3. Manage Event\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            string name, date, time, location;
            cout << "Enter event name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter event date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter event time (HH:MM): ";
            getline(cin, time);
            cout << "Enter event location: ";
            getline(cin, location);
            eventManager.createEvent(name, date, time, location);
        } else if (choice == 2) {
            eventManager.listEvents();
        } else if (choice == 3) {
            string eventName;
            cout << "Enter event name to manage: ";
            cin.ignore();
            getline(cin, eventName);
            Event* event = eventManager.findEvent(eventName);
            if (event) {
                int eventChoice;
                while (true) {
                    cout << "\n--- Manage Event: " << eventName << " ---\n";
                    cout << "1. Add Guest\n";
                    cout << "2. Remove Guest\n";
                    cout << "3. Track RSVP\n";
                    cout << "4. Send Reminder\n";
                    cout << "5. Generate Report\n";
                    cout << "6. Back\n";
                    cout << "Enter your choice: ";
                    cin >> eventChoice;
                    if (eventChoice == 1) {
                        string guestName;
                        cout << "Enter guest name: ";
                        cin.ignore();
                        getline(cin, guestName);
                        event->addGuest(guestName);
                    } else if (eventChoice == 2) {
                        string guestName;
                        cout << "Enter guest name to remove: ";
                        cin.ignore();
                        getline(cin, guestName);
                        event->removeGuest(guestName);
                    } else if (eventChoice == 3) {
                        string guestName;
                        bool isAttending;
                        cout << "Enter guest name: ";
                        cin.ignore();
                        getline(cin, guestName);
                        cout << "Is attending (1 for Yes, 0 for No): ";
                        cin >> isAttending;
                        event->trackRSVP(guestName, isAttending);
                    } else if (eventChoice == 4) {
                        event->sendReminder();
                    } else if (eventChoice == 5) {
                        event->generateReport();
                    } else if (eventChoice == 6) {
                        break;
                    } else {
                        cout << "Invalid choice. Try again.\n";
                    }
                }
            } else {
                cout << "Event not found.\n";
            }
        } else if (choice == 4) {
            cout << "Exiting application. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}