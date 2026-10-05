void startApp() {
        cout << "Welcome to the Music Note Trainer!" << endl;
        string name;
        cout << "Enter your name: ";
        cin >> name;
        currentUser.setName(name);
        int choice = 0;
        while (choice != 3) {
            displayMenu();
            cin >> choice;
            switch (choice) {
                case 1:
                    runExercise();
                    break;
                case 2:
                    cout << "Your current score: " << currentUser.getScore() << endl;
                    break;
                case 3:
                    cout << "Exiting the application. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }