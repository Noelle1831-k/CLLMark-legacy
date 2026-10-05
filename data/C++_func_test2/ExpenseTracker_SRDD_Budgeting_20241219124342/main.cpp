int main() {
    ExpenseManager manager;
    FileHandler fileHandler;
    int choice;
    bool running = true;
    while (running) {
        cout << "Expense Tracker Menu:\n";
        cout << "1. Add Expense\n";
        cout << "2. Remove Expense\n";
        cout << "3. List Expenses\n";
        cout << "4. Calculate Total\n";
        cout << "5. Save to File\n";
        cout << "6. Load from File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                manager.addExpense();
                break;
            case 2:
                manager.removeExpense();
                break;
            case 3:
                manager.listExpenses();
                break;
            case 4:
                manager.calculateTotal();
                break;
            case 5:
                fileHandler.saveToFile(manager);
                break;
            case 6:
                fileHandler.loadFromFile(manager);
                break;
            case 7:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}