int main() {
    User user;
    Budget budget;
    RecommendationEngine engine;
    Transaction transaction;
    int choice;
    do {
        cout << "\n=== SmartBudget Application ===\n";
        cout << "1. Set User Details\n";
        cout << "2. Add Transaction\n";
        cout << "3. Display User Details\n";
        cout << "4. Display Budget Summary\n";
        cout << "5. Generate Recommendations\n";
        cout << "6. Display All Transactions\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                user.setUserDetails();
                break;
            case 2:
                transaction.addTransaction(budget);
                break;
            case 3:
                user.displayUserDetails();
                break;
            case 4:
                budget.displayBudgetSummary();
                break;
            case 5:
                engine.generateRecommendations();
                engine.displayRecommendations();
                break;
            case 6:
                transaction.displayTransactions();
                break;
            case 7:
                cout << "Exiting SmartBudget. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    return 0;
}