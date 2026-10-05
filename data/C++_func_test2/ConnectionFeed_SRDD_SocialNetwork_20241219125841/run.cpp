void Application::run() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                handleAddUser();
                break;
            case 2:
                handleSendMessage();
                break;
            case 3:
                handleListConnections();
                break;
            case 4:
                cout << "Exiting application." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}