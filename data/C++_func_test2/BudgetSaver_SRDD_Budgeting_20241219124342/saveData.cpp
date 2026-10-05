void FileHandler::saveData(const vector<Expense>& expenses) {
    ofstream file("expenses.txt");
    for (const auto& expense : expenses) {
    }
    file.close();
}