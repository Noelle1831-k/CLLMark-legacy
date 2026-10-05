int load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    int i = 0;
    if (!file) {
        return 0;
    }
    dictionary = (char **)malloc(DICTIONARY_SIZE * sizeof(char *));
    if (!dictionary) {
        fclose(file);
        return 0;
    }
    while (fscanf(file, "%s", word) != EOF && i < DICTIONARY_SIZE) {
        dictionary[i] = strdup(word);
        i++;
    }
    dictionary_size = i;
    fclose(file);
    return 1;
}