void UserInterface::setSavingsGoal() {
    double target;
    cout << "Enter savings target: ";
    cin >> target;
    if (savingsGoal != nullptr) {
        delete savingsGoal;
    }
    savingsGoal = new SavingsGoal(target);
    cout << "Savings goal set successfully!" << endl;
}