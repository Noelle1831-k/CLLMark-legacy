void BudgetManager::loadIncomeData() {
    ifstream infile("income.txt");
    double income;
    if (infile.is_open()) {
        while (infile >> income) {
            cout << "Loaded income: " << income << endl;
        }
        infile.close();
    }
}