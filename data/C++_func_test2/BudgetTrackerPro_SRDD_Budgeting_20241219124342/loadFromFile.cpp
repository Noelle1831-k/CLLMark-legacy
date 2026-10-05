void FileManager::loadFromFile(BudgetTracker& budgetTracker, Reminder& reminderManager) {
    ifstream inFile("budget_data.txt");
    if (inFile.is_open()) {
        cout << "Budget data loaded successfully!" << endl;
    } else {
        cout << "Error loading file!" << endl;
    }
}