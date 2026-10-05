void displayMenu() {
        int choice;
        do {
            cout << "\nSelect an activity:" << endl;
            cout << "1. Guided Meditation" << endl;
            cout << "2. Breathing Exercises" << endl;
            cout << "3. Mindfulness Game" << endl;
            cout << "4. Puzzle" << endl;
            cout << "5. Journaling" << endl;
            cout << "6. Coloring Book" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            chooseActivity(choice);
        } while (choice != 0);
    }