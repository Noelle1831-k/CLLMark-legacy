void ExpenseManager::saveData() {
    ofstream file("expenses.txt");
    for (size_t i = 0; i < expenses.size(); i++) {
        file << "Expense " << expenses[i].first << " " << expenses[i].second << endl;
    }
    for (size_t i = 0; i < incomes.size(); i++) {
        file << "Income " << incomes[i].first << " " << incomes[i].second << endl;
    }
    file.close();
}