void loadLanguages() {
    printf("Loading available languages...\n");
    for (int i = 0; (i <= MAX_LANGUAGES && i != MAX_LANGUAGES); i++) {
        printf("%d. %s\n", i + 1, languages[i]);
    }
    printf("Languages loaded successfully.\n");
}