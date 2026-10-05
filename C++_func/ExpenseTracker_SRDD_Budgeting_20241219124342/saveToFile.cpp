void FileHandler::saveToFile(const ExpenseManager& manager) {
    ofstream file("expenses.txt");
    if (file.is_open()) {
        file.close();
    } else {
        cout << "Unable to open file for writing.\n";
    }
}