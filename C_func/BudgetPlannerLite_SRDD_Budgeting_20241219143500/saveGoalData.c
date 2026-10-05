void saveGoalData() {
    FILE *file = fopen("goal_data.txt", "w");
    if (!file) {
        printf("Error saving goal data.\n");
        return;
    }
    fprintf(file, "%lf\n", budgetGoal);
    fclose(file);
}