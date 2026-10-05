int main() {
    ExpenseManager expenseManager;
    FileManager fileManager;
    Visualization visualizer;
    Recommendations recommendations;
    int choice;
    do {
        cout << "\n====== Financial Expense Analyzer ======" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View Summary" << endl;
        cout << "3. View Recommendations" << endl;
        cout << "4. Save Data to File" << endl;
        cout << "5. Load Data from File" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                expenseManager.addExpense();
                break;
            case 2:
                visualizer.displaySummary(expenseManager);
                break;
            case 3:
                recommendations.generateSuggestions(expenseManager);
                break;
            case 4:
                fileManager.saveData(expenseManager);
                break;
            case 5:
                fileManager.loadData(expenseManager);
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}