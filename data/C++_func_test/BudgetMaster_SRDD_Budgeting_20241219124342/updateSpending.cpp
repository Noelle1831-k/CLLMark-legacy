void Budget::updateSpending(const string &category, double amount) {
    if (currentSpending.find(category) != currentSpending.end()) {
        currentSpending[category] += amount;
    }
}