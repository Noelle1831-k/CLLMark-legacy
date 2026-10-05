void WordQuizzer::displayMenu() {
    int choice;
    do {
        cout << "Welcome to WordQuizzer!" << endl;
        cout << "1. Start Quiz" << endl;
        cout << "2. View Progress" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                startQuiz();
                break;
            case 2:
                progress.displayProgress();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}