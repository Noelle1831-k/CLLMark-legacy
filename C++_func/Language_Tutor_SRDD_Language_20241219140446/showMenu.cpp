void showMenu() {
        int choice;
        do {
            cout << "\n--- Language Tutor Main Menu ---\n";
            cout << "1. Grammar Lesson\n";
            cout << "2. Vocabulary Exercise\n";
            cout << "3. Pronunciation Practice\n";
            cout << "4. Take Quiz\n";
            cout << "5. Exit\n";
            cout << "Please choose an option (1-5): ";
            cin >> choice;
            switch (choice) {
                case 1: chooseGrammar(); break;
                case 2: chooseVocabulary(); break;
                case 3: choosePronunciation(); break;
                case 4: takeQuiz(); break;
                case 5: cout << "Exiting the application... Goodbye!\n"; break;
                default: cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 5);
    }