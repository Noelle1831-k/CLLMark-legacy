void UserInterface::setSavingsGoal() {
    double target;
    cout << "Enter savings target: ";
    scanf("%f", &target);
    if (savingsGoal != nullptr) {
        delete savingsGoal;
    }
    savingsGoal = new SavingsGoal(target);
    cout << "Savings goal set successfully!" << endl;
}