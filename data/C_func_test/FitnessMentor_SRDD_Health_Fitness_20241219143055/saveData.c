void saveData() {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "Users:\n");
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %d %s %s %d %s %d\n", users[i].name, users[i].age, users[i].gender, users[i].fitnessGoal, users[i].fitnessLevel, users[i].equipment, users[i].workoutDuration);
    }
    fprintf(file, "Exercises:\n");
    for (int i = 0; i < exerciseCount; i++) {
        fprintf(file, "%s %s %s %s\n", exercises[i].name, exercises[i].muscleGroup, exercises[i].instructions, exercises[i].videoLink);
    }
    fprintf(file, "Workout Plans:\n");
    for (int i = 0; i < workoutPlanCount; i++) {
        fprintf(file, "%s %d\n", workoutPlans[i].userName, workoutPlans[i].exerciseCount);
        for (int j = 0; j < workoutPlans[i].exerciseCount; j++) {
            fprintf(file, "%s\n", workoutPlans[i].exercises[j].name);
        }
    }
    fclose(file);
    printf("Data saved successfully.\n");
}