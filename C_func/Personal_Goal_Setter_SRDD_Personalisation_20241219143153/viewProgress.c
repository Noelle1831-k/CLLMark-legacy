void viewProgress(Goal goals[MAX_GOALS], Progress progress[MAX_GOALS], int goalCount) {
    for (int i = 0; i < goalCount; i++) {
        printf("Goal: %s\n", goals[i].name);
        printf("Target: %d\n", goals[i].target);
        printf("Progress: %d\n", progress[i].currentProgress);
        printf("--------------------\n");
    }
}