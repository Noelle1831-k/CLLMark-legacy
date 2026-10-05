void trackGoals() {
    int numGoals;
    printf("Enter the number of financial goals you have: ");
    numGoals = getValidatedInteger();
    char **goalNames = (char **)malloc(numGoals * sizeof(char *));
    double *goalAmounts = (double *)malloc(numGoals * sizeof(double));
    double *currentSavings = (double *)malloc(numGoals * sizeof(double));
    if (!goalNames || !goalAmounts || !currentSavings) {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int i = 0; i < numGoals; i++) {
        goalNames[i] = (char *)malloc(100 * sizeof(char));
        if (!goalNames[i]) {
            printf("Memory allocation failed for goal name.\n");
            return;
        }
        printf("Enter the name of goal %d: ", i + 1);
        fgets(goalNames[i], 100, stdin);
        goalNames[i][strcspn(goalNames[i], "\n")] = '\0'; 
        printf("Enter the target amount for goal %d: $", i + 1);
        goalAmounts[i] = getValidatedDouble();
        printf("Enter your current savings for goal %d: $", i + 1);
        currentSavings[i] = getValidatedDouble();
    }
    printf("\nFinancial Goals Tracking Summary:\n");
    for (int i = 0; i < numGoals; i++) {
        printf("Goal: %s, Target Amount: $%.2f, Current Savings: $%.2f\n",
               goalNames[i], goalAmounts[i], currentSavings[i]);
        double remainingAmount = goalAmounts[i] - currentSavings[i];
        if (remainingAmount > 0) {
            printf("Remaining Amount to Reach Goal: $%.2f\n", remainingAmount);
        } else {
            printf("Goal reached!\n");
        }
    }
    free(goalNames);
    free(goalAmounts);
    free(currentSavings);
}