void Dashboard::displayProjectMenu(Project& project) {
    int choice;
    while (true) {
        cout << "\n--- Manage Project: " << project.getName() << " ---\n";
        cout << "1. View Details\n";
        cout << "2. Add Team Member\n";
        cout << "3. Update Status\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        switch (choice) {
            case 1:
                project.displayDetails();
                break;
            case 2: {
                string member;
                cout << "Enter team member name: ";
                getline(cin, member);
                project.addTeamMember(member);
                break;
            }
            case 3: {
                string status;
                cout << "Enter new status: ";
                getline(cin, status);
                project.updateStatus(status);
                break;
            }
            case 4:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}