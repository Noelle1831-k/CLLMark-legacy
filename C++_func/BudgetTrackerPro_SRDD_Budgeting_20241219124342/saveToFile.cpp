void FileManager::saveToFile(const BudgetTracker& budgetTracker, const Reminder& reminderManager) {
    ofstream outFile("budget_data.txt");
    if (outFile.is_open()) {
        outFile << "Budget data saved successfully!" << endl;
    } else {
        cout << "Error saving file!" << endl;
    }
}