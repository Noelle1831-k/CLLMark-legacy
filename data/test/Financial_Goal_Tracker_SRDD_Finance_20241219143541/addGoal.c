void addGoal(Goal goals[], int *goalCount) {
    if (*goalCount >= MAX_GOALS) {
        printf("Maximum number of goals reached.\n");
        return;
    }
    Goal newGoal;
    printf("Enter goal name: ");
    fgets(newGoal.name, MAX_NAME_LENGTH, stdin);
    newGoal.name[strcspn(newGoal.name, "\n")] = '\0'; 
    printf("Enter target amount: ");
    scanf("%lf", &newGoal.targetAmount);
    clearBuffer(); 
    newGoal.currentAmount = 0;
    newGoal.milestoneCount = 0;
    *(goals + *goalCount) = newGoal;
    (*goalCount)++;
    printf("Goal added successfully.\n");
}