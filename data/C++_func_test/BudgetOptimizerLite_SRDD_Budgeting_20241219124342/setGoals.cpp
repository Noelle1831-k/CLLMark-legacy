void UserInterface::setGoals() {
    double goal;
    cout << "Enter your savings goal: ";
    validateInput(goal);
    budgetManager.setSavingsGoal(goal);
}