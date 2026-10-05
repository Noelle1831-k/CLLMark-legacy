void load_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open word database.\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        if (token != NULL) {
            strcpy(word_list[word_count].word, token);
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            word_list[word_count].difficulty = atoi(token);
        }
        word_count++;
    }
    fclose(file);
}