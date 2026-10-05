void Budget::addCategory(const string &category, double limit) {
    categoryLimits[category] = limit;
    currentSpending[category] = 0.0;
}