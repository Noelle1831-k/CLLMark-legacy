int saveDictionary() {
    FILE *file = fopen("dictionary.dat", "w");
    if (!file) {
        perror("Failed to open dictionary file");
        return 0;
    }
    saveTranslationsToFile(file);
    fclose(file);
    return 1;
}