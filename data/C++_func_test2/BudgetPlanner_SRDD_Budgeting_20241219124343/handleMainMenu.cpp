void handleMainMenu(BudgetPlanner &planner, FileHandler &fileHandler) {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            planner.addExpense();
            break;
        case 2: {
            double income;
            cout << "Enter your total income: ";
            cin >> income;
            planner.calculateSavings(income);
            break;
        }
        case 3:
            planner.displayBudgetSummary();
            break;
        case 4:
            fileHandler.saveToFile("budget_data.txt", planner);
            break;
        case 5:
            fileHandler.loadFromFile("budget_data.txt", planner);
            break;
        case 6:
            cout << "Thank you for using BudgetPlanner. Goodbye!" << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again!" << endl;
            break;
    }
}