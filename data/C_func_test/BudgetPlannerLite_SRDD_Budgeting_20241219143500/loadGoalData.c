void loadGoalData() {
    FILE *file = fopen("goal_data.txt", "r");
    if (!file) {
        return; 
    }
    fscanf(file, "%lf", &budgetGoal);
    fclose(file);
}