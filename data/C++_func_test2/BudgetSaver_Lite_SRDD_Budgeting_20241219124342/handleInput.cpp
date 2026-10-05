void UserInterface::handleInput(int choice) {
    switch (choice) {
        case 1: {
            double amount;
            string source;
            cout << "Enter income amount: ";
            cin >> amount;
            cout << "Enter income source: ";
            cin >> source;
            manager.addIncome(amount, source);
            break;
        }
        case 2: {
            double amount;
            string category;
            cout << "Enter expense amount: ";
            cin >> amount;
            cout << "Enter expense category: ";
            cin >> category;
            manager.addExpense(amount, category);
            break;
        }
        case 3: {
            double goal;
            cout << "Enter budget goal: ";
            cin >> goal;
            manager.setBudgetGoal(goal);
            break;
        }
        case 4:
            manager.generateReport();
            break;
        case 5: {
            cout << "Visualizing Income Data:" << endl;
            visualizer.displayPieChart(manager.getIncomeBreakdown());
            cout << "Visualizing Expense Data:" << endl;
            visualizer.displayBarChart(manager.getExpenseBreakdown());
            break;
        }
        case 6:
            cout << "Exiting BudgetSaver Lite. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}