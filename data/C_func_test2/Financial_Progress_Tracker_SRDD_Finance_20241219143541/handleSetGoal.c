void handleSetGoal() {
    char goalName[100];
    double targetAmount;
    printf("Enter goal name: ");
    scanf("%s", goalName);
    printf("Enter target amount: ");
    scanf("%lf", &targetAmount);
    addGoal(goalName, targetAmount);
}