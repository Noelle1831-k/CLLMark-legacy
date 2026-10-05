int main() {
    ExpenseManager expenseManager;
    CategoryManager categoryManager;
    ReportGenerator reportGenerator;
    expenseManager.loadData(); 
    while (true) {
        displayMainMenu();
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            expenseManager.addExpense();
            break;
        case 2:
            expenseManager.addIncome();
            break;
        case 3:
            reportGenerator.generateReport(expenseManager);
            break;
        case 4:
            categoryManager.manageCategories();
            break;
        case 5:
            expenseManager.saveData(); 
            cout << "Exiting... Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}