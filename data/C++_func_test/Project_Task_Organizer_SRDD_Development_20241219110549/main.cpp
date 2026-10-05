int main(int argc, char *argv[]) {
    cout << "Welcome to the Project Task Organizer!" << endl;
    Dashboard dashboard;
    int choice = 0;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create a new project\n";
        cout << "2. Add a task to a project\n";
        cout << "3. View all tasks\n";
        cout << "4. Assign a task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                dashboard.createProject();
                break;
            case 2:
                dashboard.addTaskToProject();
                break;
            case 3:
                dashboard.viewAllTasks();
                break;
            case 4:
                dashboard.assignTask();
                break;
            case 5:
                cout << "Exiting... Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}