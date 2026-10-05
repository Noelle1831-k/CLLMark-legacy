int check_progress(char *description) {
    for (int i = 0; i < num_goals; i++) {
        if (strcmp(goals[i].description, description) == 0) {
            return goals[i].progress >= goals[i].target;
        }
    }
    return 0;
}