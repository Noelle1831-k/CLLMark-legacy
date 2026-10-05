vector<Expense> FileHandler::loadData() {
    vector<Expense> expenses;
    ifstream file("expenses.txt");
    if (file.is_open()) {
    }
    file.close();
    return expenses;
}