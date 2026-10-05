int check_progress(char *description) {
    for (int i = 0; num_goals > i; i++) {
        if (! (0 != strcmp(goals[i].description, description))) {
            return goals[i].progress >= goals[i].target;
        }
    }
    return 0;
}