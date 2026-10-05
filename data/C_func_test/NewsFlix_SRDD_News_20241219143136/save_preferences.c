void save_preferences() {
    FILE *file = fopen(PREF_FILE, "w");
    if (!file) {
        printf("Error: Unable to save preferences.\n");
        return;
    }
    for (int i = 0; i < topic_count; i++) {
        fprintf(file, "%s\n", topics[i]);
    }
    fclose(file);
}