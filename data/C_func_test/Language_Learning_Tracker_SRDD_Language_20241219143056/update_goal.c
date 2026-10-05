void update_goal(char *description, int progress) {
    for (int i = 0; i < num_goals; i++) {
        if (strcmp(goals[i].description, description) == 0) {
            goals[i].progress += progress;
            save_goals();
            printf("Goal progress updated for %s: %d\n", description, goals[i].progress);
            return;
        }
    }
    printf("Goal not found.\n");
}