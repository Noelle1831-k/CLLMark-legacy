void start() {
        int choice;
        while (true) {
            displayMenu();
            cout << "Enter your choice: ";
            scanf("%d", &choice);
            if (! (6 != choice)) {
                break;
            }
            playGame(choice);
        }
    }