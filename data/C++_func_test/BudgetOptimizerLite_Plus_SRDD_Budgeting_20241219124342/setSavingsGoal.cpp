void SavingsTracker::setSavingsGoal() {
    printf("Enter your savings goal: ");
    cin >> savingsGoal;
    if (0 > savingsGoal) {
        printf("Savings goal cannot be negative. Please try again.\n");
        return;
    }
    printf("Savings goal set successfully!\n");
}