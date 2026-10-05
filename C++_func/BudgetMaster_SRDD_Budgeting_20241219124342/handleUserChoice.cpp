void handleUserChoice(BudgetMasterApp &app, int choice) {
    switch (choice) {
        case 1:
            app.addTransaction();
            break;
        case 2:
            app.viewBudget();
            break;
        case 3:
            app.generateReport();
            break;
        case 4:
            app.setBudgetGoals();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}