int main() {
    BudgetManager budgetManager;
    Visualizer visualizer;
    InputHandler inputHandler;
    FileManager fileManager;
    cout << "Welcome to BudgetOptimizerLiteEZ!" << endl;
    while (true) {
        displayMenu();
        int choice = inputHandler.getValidatedInt("Enter your choice: ");
        switch (choice) {
            case 1: {
                double amount = inputHandler.getValidatedDouble("Enter income amount: ");
                string source = inputHandler.getValidatedString("Enter income source: ");
                budgetManager.addIncome(amount, source);
                break;
            }
            case 2: {
                double amount = inputHandler.getValidatedDouble("Enter expense amount: ");
                string category = inputHandler.getValidatedString("Enter expense category: ");
                budgetManager.addExpense(amount, category);
                break;
            }
            case 3: {
                double goal = inputHandler.getValidatedDouble("Enter budget goal: ");
                budgetManager.setBudgetGoal(goal);
                break;
            }
            case 4: {
                budgetManager.generateReport();
                visualizer.generatePieChart(budgetManager.getIncomes(), budgetManager.getExpenses());
                visualizer.generateBarGraph(budgetManager.getIncomes(), budgetManager.getExpenses());
                break;
            }
            case 5: {
                string filename = inputHandler.getValidatedString("Enter filename to save data: ");
                fileManager.saveToFile(filename, budgetManager);
                break;
            }
            case 6: {
                string filename = inputHandler.getValidatedString("Enter filename to load data: ");
                fileManager.loadFromFile(filename, budgetManager);
                break;
            }
            case 7:
                cout << "Exiting BudgetOptimizerLiteEZ. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}