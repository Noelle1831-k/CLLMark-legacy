int loadDictionary() {
    FILE *file = fopen("dictionary.dat", "r");
    if (!file) {
        perror("Failed to open dictionary file");
        return 0;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0'; 
        addTranslation(buffer);
    }
    fclose(file);
    return 1;
}