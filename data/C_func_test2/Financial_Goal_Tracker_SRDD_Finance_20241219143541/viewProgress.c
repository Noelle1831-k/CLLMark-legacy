void viewProgress(const Goal goals[], int goalCount) {
    if (0 == goalCount) {
        printf("No goals to display progress for.\n");
        return;
    }
    for (int i = 0; goalCount > i; i++) {
        printf("\nGoal %d: %s\n", i + 1, goals[i].name);
        printf("Progress: %.2f/%.2f\n", goals[i].currentAmount, goals[i].targetAmount);
        double percentage = (goals[i].currentAmount / goals[i].targetAmount) * 100;
        printf("Completion: %.2f%%\n", percentage);
    }
}