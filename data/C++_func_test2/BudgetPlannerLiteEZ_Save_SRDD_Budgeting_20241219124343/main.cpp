int main() {
    BudgetManager manager;
    Visualizer visualizer;
    FileHandler fileHandler;
    string choice;
    while (true) {
        cout << "\n=== Budgeting Software ===\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. Set Savings Goal\n";
        cout << "4. View Budget Report\n";
        cout << "5. Save Budget to File\n";
        cout << "6. Load Budget from File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == "1") {
            double income;
            cout << "Enter income amount: ";
            cin >> income;
            manager.addIncome(income);
        } else if (choice == "2") {
            double expense;
            string category;
            cout << "Enter expense amount: ";
            cin >> expense;
            cout << "Enter expense category: ";
            cin >> category;
            manager.addExpense(expense, category);
        } else if (choice == "3") {
            double goal;
            cout << "Enter savings goal: ";
            cin >> goal;
            manager.setSavingsGoal(goal);
        } else if (choice == "4") {
            manager.generateReport();
            visualizer.displayPieChart(manager.getExpenses());
            visualizer.displaySavingsProgress(manager.getSavings(), manager.getSavingsGoal());
        } else if (choice == "5") {
            string filename;
            cout << "Enter filename to save: ";
            cin >> filename;
            fileHandler.saveToFile(filename, manager);
        } else if (choice == "6") {
            string filename;
            cout << "Enter filename to load: ";
            cin >> filename;
            fileHandler.loadFromFile(filename, manager);
        } else if (choice == "7") {
            cout << "Exiting application. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}