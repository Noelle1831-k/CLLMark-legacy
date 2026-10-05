void FileHandler::loadFromFile(ExpenseManager& manager) {
    ifstream file("expenses.txt");
    if (file.is_open()) {
        file.close();
    } else {
        cout << "Unable to open file for reading.\n";
    }
}