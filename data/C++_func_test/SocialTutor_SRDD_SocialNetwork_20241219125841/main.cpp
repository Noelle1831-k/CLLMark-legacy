int main() {
    SystemManager systemManager;
    int choice = 0;
    cout << "Welcome to SocialTutor!" << endl;
    while (true) {
        cout << "\nMenu:\n1. Register User\n2. Search for Tutors\n3. Send a Message\n4. Schedule a Session\n5. List All Sessions\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                systemManager.addUser();
                break;
            case 2:
                systemManager.searchBySubject();
                break;
            case 3:
                systemManager.manageMessages();
                break;
            case 4:
                systemManager.manageSessions();
                break;
            case 5:
                systemManager.listSessions();
                break;
            case 6:
                cout << "Thank you for using SocialTutor. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}