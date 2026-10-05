int main() {
    ExpenseManager expenseManager;
    RecommendationEngine recommendationEngine;
    UserInterface ui;
    while (true) {
        ui.displayMenu();
        int choice = ui.getUserInput();
        switch (choice) {
            case 1:
                ui.showExpenses(expenseManager);
                break;
            case 2:
                expenseManager.addExpense();
                break;
            case 3:
                ui.showRecommendations(recommendationEngine, expenseManager);
                break;
            case 4:
                cout << "Exiting the program. Thank you for using Personal Finance Management Software!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}