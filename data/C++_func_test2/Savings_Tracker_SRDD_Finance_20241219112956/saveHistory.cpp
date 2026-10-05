void HistoryManager::saveHistory(const SavingsTracker& tracker) {
    ofstream history_file("savings_history.txt", ios::app);
    if (history_file.is_open()) {
        history_file << "User: " << tracker.getUser() << endl;
        history_file << "Goal: $" << tracker.getGoal() << endl;
        history_file << "Current savings: $" << tracker.getCurrentSavings() << endl;
        history_file << "Progress after " << tracker.getMonthsLeft() << " months: ";
        history_file << (tracker.getCurrentSavings() / tracker.getGoal()) * 100 << "%" << endl;
        history_file << "--------------------------------------------\n";
        history_file.close();
        cout << "\nSavings history saved successfully.\n";
    } else {
        cout << "\nError saving history.\n";
    }
}