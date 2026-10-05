void BudgetManager::saveExpenseData(double expense) {
    ofstream outfile("expenses.txt", ios::app);
    if (outfile.is_open()) {
        outfile << expense << endl;
        outfile.close();
    }
}