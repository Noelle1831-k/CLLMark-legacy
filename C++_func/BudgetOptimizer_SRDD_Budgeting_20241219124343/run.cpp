void run() {
        cout << "Welcome to BudgetOptimizer!" << endl;
        int choice;
        do {
            displayDashboard();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    handleIncome();
                    break;
                case 2:
                    handleExpenses();
                    break;
                case 3:
                    handleBudgetGoal();
                    break;
                case 4:
                    analyzeSpending();
                    break;
                case 5:
                    cout << "Exiting BudgetOptimizer. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 5);
    }