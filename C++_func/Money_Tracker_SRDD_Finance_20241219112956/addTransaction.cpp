void MoneyTracker::addTransaction() {
    double amount;
    std::string category, type;
    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cout << "Enter category: ";
    std::cin >> category;
    std::cout << "Enter type (income/expense): ";
    std::cin >> type;
    Transaction transaction(amount, category, type);
    bool categoryExists = false;
    for (size_t i = 0; i < categories.size(); ++i) {
        if (categories[i].getName() == category) {
            categories[i].addTransaction(transaction);
            categoryExists = true;
            break;
        }
    }
    if (!categoryExists) {
        Category newCategory(category);
        newCategory.addTransaction(transaction);
        categories.push_back(newCategory);
    }
}