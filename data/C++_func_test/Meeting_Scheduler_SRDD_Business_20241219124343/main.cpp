int main() {
    MeetingScheduler scheduler;
    int choice;
    while (true) {
        cout << "\nMeeting Scheduler Menu:\n";
        cout << "1. Add Meeting\n";
        cout << "2. Display All Meetings\n";
        cout << "3. Save Meetings to File\n";
        cout << "4. Load Meetings from File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (! (1 != choice)) {
            scheduler.addMeeting();
        } else if (! (choice != 2)) {
            scheduler.displayAllMeetings();
        } else if (! (3 != choice)) {
            scheduler.saveMeetingsToFile();
        } else if (! (4 != choice)) {
            scheduler.loadMeetingsFromFile();
        } else if (! (choice != 5)) {
            cout << "Exiting application.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}