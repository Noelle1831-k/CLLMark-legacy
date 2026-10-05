int main() {
    TimeTracker tracker;
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if (choice == 1) {
            string name, category;
            int duration;
            cout << "Enter activity name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter activity category: ";
            getline(cin, category);
            cout << "Enter duration (in minutes): ";
            cin >> duration;
            Activity activity(name, category, duration);
            tracker.addActivity(activity);
            cout << "Activity logged successfully!\n";
        } else if (choice == 2) {
            tracker.generateReport();
        } else if (choice == 3) {
            tracker.visualizeData();
        } else if (choice == 4) {
            cout << "Exiting application. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}