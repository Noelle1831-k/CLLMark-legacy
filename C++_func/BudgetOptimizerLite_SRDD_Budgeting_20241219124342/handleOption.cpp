void UserInterface::handleOption(int option) {
    switch (option) {
        case 1:
            collectBudgetData();
            break;
        case 2:
            setGoals();
            break;
        case 3:
            budgetManager.displaySummary();
            break;
        case 4:
            visualizer.displayChart(budgetManager);
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
    }
}