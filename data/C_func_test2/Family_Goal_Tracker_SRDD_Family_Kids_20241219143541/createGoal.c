void createGoal() {
    if (goalCount >= MAX_GOALS) {
        printf("Goal limit reached. Cannot add more goals.\n");
        return;
    }
    Goal newGoal;
    printf("Enter goal name: ");
    scanf(" %[^\n]", newGoal.name);
    printf("Enter deadline (in days from today): ");
    if (scanf("%d", &newGoal.deadline) != 1 || newGoal.deadline < 0) {
        printf("Invalid deadline. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    newGoal.progress = 0;
    strcpy(newGoal.assignedTo, "Unassigned");
    goals[goalCount++] = newGoal;
    printf("Goal created successfully.\n");
}