void BudgetManager::loadExpenseData() {
    ifstream infile("expenses.txt");
    double expense;
    if (infile.is_open()) {
        while (infile >> expense) {
            cout << "Loaded expense: " << expense << endl;
        }
        infile.close();
    }
}