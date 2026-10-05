void UserInterface::handleUserInput(int choice) {
    double amount;
    string description;
    switch (choice) {
        case 1:
            amount = getValidDoubleInput("Enter income amount: ");
            cout << "Enter income source: ";
            cin.ignore();
            getline(cin, description);
            budgetManager.addIncome(amount, description);
            break;
        case 2:
            amount = getValidDoubleInput("Enter expense amount: ");
            cout << "Enter expense category: ";
            cin.ignore();
            getline(cin, description);
            budgetManager.addExpense(amount, description);
            break;
        case 3:
            amount = getValidDoubleInput("Enter budget goal: ");
            budgetManager.setBudgetGoal(amount);
            break;
        case 4:
            if (budgetManager.checkBudgetGoal()) {
                cout << "Budget goal met!" << endl;
            } else {
                cout << "Budget goal not met." << endl;
            }
            break;
        case 5:
            amount = getValidDoubleInput("Enter savings goal: ");
            savingsTracker.setSavingsGoal(amount);
            break;
        case 6:
            amount = getValidDoubleInput("Enter savings amount: ");
            savingsTracker.addSavings(amount);
            break;
        case 7:
            budgetManager.displayBudgetBreakdown();
            break;
        case 8:
            savingsTracker.displaySavingsProgress();
            break;
        case 9:
            cout << "Exiting application. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}