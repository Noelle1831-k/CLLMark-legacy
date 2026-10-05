int main() {
    cout << "Welcome to the Music Scale Trainer!" << endl;
    ScaleTrainer scaleTrainer;
    UserProgress userProgress;
    AudioManager audioManager;
    bool running = true;
    while (running) {
        int choice;
        cout << "\nMenu Options:\n";
        cout << "1. Start Exercise\n";
        cout << "2. View Progress\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                scaleTrainer.startExercise(userProgress, audioManager);
                break;
            case 2:
                userProgress.displayProgress();
                break;
            case 3:
                running = false;
                cout << "Exiting the application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3.\n" << endl;
        }
    }
    return 0;
}