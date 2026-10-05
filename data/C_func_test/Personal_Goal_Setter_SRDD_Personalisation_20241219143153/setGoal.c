void setGoal(Goal goals[MAX_GOALS], int *goalCount) {
    if (*goalCount >= MAX_GOALS) {
        printf("Maximum number of goals reached.\n");
        return;
    }
    Goal newGoal;
    printf("Enter the name of the goal: ");
    getchar();  
    fgets(newGoal.name, sizeof(newGoal.name), stdin);
    newGoal.name[strcspn(newGoal.name, "\n")] = '\0'; 
    printf("Enter the type of the goal (0: Fitness, 1: Career, 2: Personal Development): ");
    int type;
    scanf("%d", &type);
    newGoal.type = type;
    printf("Enter the target for this goal: ");
    scanf("%d", &newGoal.target);
    newGoal.progress = 0; 
    goals[*goalCount] = newGoal;
    (*goalCount)++;
    printf("Goal '%s' has been added successfully!\n", newGoal.name);
}