int main() {
    EventManager manager;
    int choice;
    cout << "Welcome to the Office Event Management System!" << endl;
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Create Event" << endl;
        cout << "2. Manage Tasks" << endl;
        cout << "3. Manage Budget" << endl;
        cout << "4. Manage Vendors" << endl;
        cout << "5. Send Reminders" << endl;
        cout << "6. Collect Feedback" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                manager.createEvent();
                break;
            case 2:
                manager.manageTasks();
                break;
            case 3:
                manager.manageBudget();
                break;
            case 4:
                manager.manageVendors();
                break;
            case 5:
                manager.sendReminders();
                break;
            case 6:
                manager.collectFeedback();
                break;
            case 7:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}