void UserInterface::showProgress() {
    if (savingsGoal == nullptr) {
        cout << "Please set a savings goal first." << endl;
        return;
    }
    cout << "Current Progress: " << savingsGoal->getProgress() << "%" << endl;
}