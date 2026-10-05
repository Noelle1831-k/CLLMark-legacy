int main() {
    Dashboard dashboard;
    int choice;
    while (true) {
        cout << "\n--- Office Project Tracker (OPT) ---\n";
        cout << "1. Create Project\n";
        cout << "2. List Projects\n";
        cout << "3. Manage Project\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        switch (choice) {
            case 1: {
                string name, deadline, description;
                cout << "Enter project name: ";
                getline(cin, name);
                cout << "Enter project deadline: ";
                getline(cin, deadline);
                cout << "Enter project description: ";
                getline(cin, description);
                dashboard.createProject(name, deadline, description);
                break;
            }
            case 2:
                dashboard.listProjects();
                break;
            case 3: {
                int projectId;
                cout << "Enter project ID to manage: ";
                cin >> projectId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                dashboard.manageProject(projectId);
                break;
            }
            case 4:
                cout << "Exiting OPT. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}