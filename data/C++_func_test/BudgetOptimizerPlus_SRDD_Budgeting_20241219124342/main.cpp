int main() {
    displayWelcomeMessage();
    BudgetOptimizer budgetOptimizer;
    SavingsTracker savingsTracker;
    UserProfile userProfile;
    FinancialAnalyzer financialAnalyzer;
    userProfile.loadUserData();
    char userChoice;
    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Track Expenses" << endl;
        cout << "2. Analyze Spending Patterns" << endl;
        cout << "3. Analyze Financial Habits" << endl;
        cout << "4. Generate Recommendations" << endl;
        cout << "5. Set Savings Goal" << endl;
        cout << "6. Track Savings Progress" << endl;
        cout << "7. Display Dashboard" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        switch (userChoice) {
            case '1':
                budgetOptimizer.trackExpenses();
                break;
            case '2':
                financialAnalyzer.analyzeSpendingPatterns();
                break;
            case '3':
                financialAnalyzer.analyzeFinancialHabits();
                break;
            case '4':
                budgetOptimizer.generateRecommendations();
                break;
            case '5':
                savingsTracker.setSavingsGoal();
                break;
            case '6':
                savingsTracker.trackSavingsProgress();
                break;
            case '7':
                budgetOptimizer.displayDashboard();
                break;
            case '8':
                userProfile.saveUserData();
                displayExitMessage();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (userChoice != '8');
    return 0;
}