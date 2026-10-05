void UserInterface::generateReport() {
    if (savingsGoal == nullptr) {
        cout << "Please set a savings goal first." << endl;
        return;
    }
    savingsGoal->generateReport();
}