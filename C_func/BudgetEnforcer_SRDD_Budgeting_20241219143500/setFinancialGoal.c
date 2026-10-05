void setFinancialGoal() {
    printf("Enter your financial goal: ");
    if (scanf("%f", &currentUser.financialGoal) != 1) {
        handleError("Invalid input. Please enter a valid amount.");
    }
    printf("Financial goal set to %.2f\n", currentUser.financialGoal);
}