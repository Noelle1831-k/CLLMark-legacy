void show_goals() {
    printf("Displaying all active goals...\n");
    for (int i = 0; i < num_goals; i++) {
        printf("Goal: %s, Target: %d, Progress: %d\n", goals[i].description, goals[i].target, goals[i].progress);
    }
}