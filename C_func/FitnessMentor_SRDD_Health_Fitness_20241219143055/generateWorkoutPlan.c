void generateWorkoutPlan() {
    char userName[50];
    printf("Enter user name: ");
    scanf("%s", userName);
    struct WorkoutPlan newPlan;
    strcpy(newPlan.userName, userName);
    newPlan.exerciseCount = 0;
    for (int i = 0; i < 10; i++) {
        if (newPlan.exerciseCount < 10) {
            newPlan.exercises[newPlan.exerciseCount++] = exercises[i];
        }
    }
    workoutPlans[workoutPlanCount++] = newPlan;
    printf("Workout plan generated successfully!\n");
}