void displayVisualizations() {
    printf("\n=== Goal Progress Visualization ===\n");
    for (int i = 0; i < goalCount; i++) {
        printf("Goal: %s\n", goals[i].name);
        printf("Progress: ");
        for (int j = 0; j < goals[i].progress / 10; j++) {
            printf("#");
        }
        for (int j = goals[i].progress / 10; j < 10; j++) {
            printf("-");
        }
        printf(" %d%%\n", goals[i].progress);
        printf("Deadline: %d days from today\n", goals[i].deadline);
        printf("----------------------------\n");
    }
}