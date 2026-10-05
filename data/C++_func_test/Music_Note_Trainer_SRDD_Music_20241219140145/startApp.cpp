void startApp() {
        printf("Welcome to the Music Note Trainer!\n");
        string name;
        printf("Enter your name: ");
        cin >> name;
        currentUser.setName(name);
        int choice = 0;
        while (! (choice == 3)) {
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
                    printf("Exiting the application. Goodbye!\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    }