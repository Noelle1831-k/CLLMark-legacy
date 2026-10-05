void load_goals() {
    FILE *file = fopen(GOAL_FILE, "r");
    num_goals = 0;
    if (file) {
        while (fscanf(file, "%s %d %d\n", goals[num_goals].description, &goals[num_goals].target, &goals[num_goals].progress) != EOF) {
            num_goals++;
        }
        fclose(file);
    } else {
        printf("No goals found, starting fresh.\n");
    }
}