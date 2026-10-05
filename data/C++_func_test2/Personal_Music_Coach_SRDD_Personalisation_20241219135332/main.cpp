int main() {
    User user;
    PerformanceAnalyzer analyzer;
    PracticeScheduler scheduler;
    RepertoireSelector selector;
    ProgressTracker tracker;
    cout << "Welcome to the Personal Music Coach!" << endl;
    user.setDetails();
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Analyze Performance\n";
        cout << "2. Schedule Practice\n";
        cout << "3. Get Repertoire Suggestions\n";
        cout << "4. Track Progress\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                analyzer.analyzePerformance(user);
                analyzer.generateFeedback();
                break;
            case 2:
                scheduler.schedulePractice(user);
                scheduler.sendReminder();
                break;
            case 3:
                selector.suggestRepertoire(user);
                break;
            case 4:
                tracker.trackProgress(user);
                tracker.displayProgress();
                break;
            case 5:
                cout << "Thank you for using the Personal Music Coach. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}