void displayWorkoutPlan() {
    char userName[50];
    printf("Enter user name to display workout plan: ");
    scanf("%s", userName);
    for (int i = 0; i < workoutPlanCount; i++) {
        if (strcmp(workoutPlans[i].userName, userName) == 0) {
            printf("Workout Plan for %s:\n", userName);
            for (int j = 0; j < workoutPlans[i].exerciseCount; j++) {
                printf("Exercise %d: %s\n", j + 1, workoutPlans[i].exercises[j].name);
            }
            return;
        }
    }
    printf("Workout plan not found.\n");
}