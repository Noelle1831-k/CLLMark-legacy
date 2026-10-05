void updateGoalProgress(const char *name, double amount) {
    for (int i = 0; i < goalCount; i++) {
        if (strcmp(goals[i].name, name) == 0) {
            goals[i].currentAmount += amount;
            printf("Updated goal '%s' with amount %.2f.\n", name, amount);
            return;
        }
    }
    printf("Goal '%s' not found.\n", name);
}