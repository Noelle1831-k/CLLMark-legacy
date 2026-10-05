void processInput(int choice) {
        switch (choice) {
            case 1:
                user.setUserDetails();
                break;
            case 2:
                expenseManager.addExpense(user);
                break;
            case 3:
                expenseManager.displayExpenses(user);
                break;
            case 4:
                budgetAnalyzer.analyzeBudget(user, expenseManager);
                break;
            case 5:
                fileManager.saveUserData(user);
                cout << "Data saved successfully. Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }