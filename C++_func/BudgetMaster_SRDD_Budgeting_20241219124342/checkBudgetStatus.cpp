bool Budget::checkBudgetStatus(const string &category) const {
    if (currentSpending.find(category) != currentSpending.end()) {
        return currentSpending.at(category) <= categoryLimits.at(category);
    }
    return false;
}