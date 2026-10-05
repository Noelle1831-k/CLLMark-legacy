void loadData() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Users:", 6) == 0) {
            while (fgets(line, sizeof(line), file) && strncmp(line, "Exercises:", 10) != 0) {
                struct User user;
                sscanf(line, "%s %d %s %s %d %s %d", user.name, &user.age, user.gender, user.fitnessGoal, &user.fitnessLevel, user.equipment, &user.workoutDuration);
                users[userCount++] = user;
            }
        }
        if (strncmp(line, "Exercises:", 10) == 0) {
            while (fgets(line, sizeof(line), file) && strncmp(line, "Workout Plans:", 14) != 0) {
                struct Exercise exercise;
                sscanf(line, "%s %s %s %s", exercise.name, exercise.muscleGroup, exercise.instructions, exercise.videoLink);
                exercises[exerciseCount++] = exercise;
            }
        }
        if (strncmp(line, "Workout Plans:", 14) == 0) {
            while (fgets(line, sizeof(line), file)) {
                struct WorkoutPlan plan;
                sscanf(line, "%s %d", plan.userName, &plan.exerciseCount);
                for (int i = 0; i < plan.exerciseCount; i++) {
                    fgets(line, sizeof(line), file);
                    sscanf(line, "%s", plan.exercises[i].name);
                }
                workoutPlans[workoutPlanCount++] = plan;
            }
        }
    }
    fclose(file);
    printf("Data loaded successfully.\n");
}