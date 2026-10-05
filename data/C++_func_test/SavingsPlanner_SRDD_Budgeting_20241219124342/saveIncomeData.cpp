void BudgetManager::saveIncomeData(double income) {
    ofstream outfile("income.txt", ios::app);
    if (outfile.is_open()) {
        outfile << income << endl;
        outfile.close();
    }
}