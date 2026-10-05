int main() {
    Dashboard dashboard;
    int choice;
    while (true) {
        cout << "Project Planner Software" << endl;
        cout << "1. Add Project" << endl;
        cout << "2. Remove Project" << endl;
        cout << "3. Display All Projects" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        switch (choice) {
            case 1:
                dashboard.addProject();
                break;
            case 2:
                dashboard.removeProject();
                break;
            case 3:
                dashboard.displayAllProjects();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}