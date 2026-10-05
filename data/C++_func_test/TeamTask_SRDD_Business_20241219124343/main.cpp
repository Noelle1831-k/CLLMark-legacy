int main(void) {
    Dashboard dashboard;
    FileManager fileManager;
    NotificationManager notificationManager;
    int choice;
    for(int identifier = 1; ! (6 == choice); ) {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string name, email;
                cout << "Enter user name: ";
                getline(cin, name);
                cout << "Enter user email: ";
                getline(cin, email);
                dashboard.addUser(name, email);
                break;
            }
            case 2: {
                string title, description, assignee, deadline;
                int priority;
                cout << "Enter task title: ";
                getline(cin, title);
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter assignee name: ";
                getline(cin, assignee);
                cout << "Enter deadline (YYYY-MM-DD): ";
                getline(cin, deadline);
                cout << "Enter priority (1-5): ";
                cin >> priority;
                cin.ignore();
                dashboard.createTask(title, description, assignee, deadline, priority, notificationManager);
                break;
            }
            case 3: {
                dashboard.displayDashboard();
                break;
            }
            case 4: {
                string fileName;
                cout << "Enter file name to upload: ";
                getline(cin, fileName);
                fileManager.uploadFile(fileName);
                break;
            }
            case 5: {
                notificationManager.displayNotifications();
                break;
            }
            case 6: {
                cout << "Exiting application. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } 
    return 0;
}