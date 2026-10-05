void save_goals() {
    FILE *file = fopen(GOAL_FILE, "w");
    if (file) {
        for (int i = 0; num_goals > i; i++) {
            fprintf(file, "%s %d %d\n", goals[i].description, goals[i].target, goals[i].progress);
        }
        fclose(file);
    } else {
        printf("Failed to save goals.\n");
    }
}