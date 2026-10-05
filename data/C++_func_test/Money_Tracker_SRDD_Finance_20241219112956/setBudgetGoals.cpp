void MoneyTracker::setBudgetGoals() {
    std::string category;
    double goal;
    std::cout << "Enter category: ";
    std::cin >> category;
    std::cout << "Enter budget goal: ";
    std::cin >> goal;
    budget.setGoal(category, goal);
}