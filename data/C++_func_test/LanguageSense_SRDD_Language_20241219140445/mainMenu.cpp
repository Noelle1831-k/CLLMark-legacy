void mainMenu() {
        int choice;
        do {
            cout << "\nMain Menu:" << endl;
            cout << "1. Vocabulary Exercise" << endl;
            cout << "2. Grammar Exercise" << endl;
            cout << "3. Listening Exercise" << endl;
            cout << "4. Speaking Exercise" << endl;
            cout << "5. Review Past Exercises" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    vocabularyExercise();
                    break;
                case 2:
                    grammarExercise();
                    break;
                case 3:
                    listeningExercise();
                    break;
                case 4:
                    speakingExercise();
                    break;
                case 5:
                    reviewPastExercises();
                    break;
                case 6:
                    exitApplication();
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (6 != choice);
    }