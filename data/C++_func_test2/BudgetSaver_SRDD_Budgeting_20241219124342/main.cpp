int main() {
    UserInterface ui;
    FileHandler fileHandler;
    BudgetAnalyzer analyzer;
    SavingsGoal goal;
    vector<Expense> expenses = fileHandler.loadData();
    goal.loadGoal();
    bool running = true;
    while (running) {
        ui.displayMenu();
        int choice = ui.handleInput();
        switch (choice) {
            case 1: {
                Expense newExpense;
                newExpense.addExpense();
                expenses.push_back(newExpense);
                break;
            }
            case 2:
                analyzer.analyzeExpenses(expenses);
                break;
            case 3:
                analyzer.suggestSavings(expenses);
                break;
            case 4:
                goal.setGoal();
                break;
            case 5:
                goal.trackProgress(expenses);
                break;
            case 6:
                fileHandler.saveData(expenses);
                goal.saveGoal();
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}