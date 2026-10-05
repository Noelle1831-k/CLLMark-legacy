void run() {
        cout << "Welcome to Budget Buddy!" << endl;
        cout << "Choose an option:\n1. Login\n2. Register\n3. Exit\n";
        int choice;
        cin >> choice;
        User user;
        switch (choice) {
            case 1:
                if (user.login()) {
                    manageAccount(user);
                } else {
                    cout << "Login failed. Exiting application." << endl;
                }
                break;
            case 2:
                user.registerUser();
                break;
            case 3:
                cout << "Thank you for using Budget Buddy. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Exiting application." << endl;
        }
    }