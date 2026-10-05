void UserBudget::displayBudgets() const {
    for (const auto &pair : categoryBudgets) {
        cout << "Category: " << pair.first << ", Budget: $" << pair.second << endl;
    }
}