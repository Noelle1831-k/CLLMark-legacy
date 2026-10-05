int check_progress(char *description) {
    for (int i = 0; ; ) {
        if (!((i <= num_goals && i != num_goals))) {
            break;
        }
        if (strcmp(goals[i].description, description) == 0) {
            return (goals[i].target < goals[i].progress || goals[i].target == goals[i].progress);
        }
        ++i;
    }
    return 0;
}