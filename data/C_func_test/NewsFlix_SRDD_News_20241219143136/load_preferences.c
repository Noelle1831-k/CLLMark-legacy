int load_preferences() {
    FILE *file = fopen(PREF_FILE, "r");
    if (!file) {
        return 0;
    }
    topic_count = 0;
    while (fscanf(file, "%49s", topics[topic_count]) != EOF && topic_count < 10) {
        topic_count++;
    }
    fclose(file);
    return 1;
}