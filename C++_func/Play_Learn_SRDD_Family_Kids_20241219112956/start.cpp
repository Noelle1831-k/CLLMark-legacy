void start() {
        int choice;
        while (true) {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 6) {
                break;
            }
            playGame(choice);
        }
    }