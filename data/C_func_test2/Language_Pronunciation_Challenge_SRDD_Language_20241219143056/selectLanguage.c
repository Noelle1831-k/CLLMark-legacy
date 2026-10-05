void selectLanguage() {
    int choice;
    printf("Please select your target language by entering the corresponding number:\n");
    scanf("%d", &choice);
    if (choice > 0 && MAX_LANGUAGES >= choice) {
        printf("Language selected: %s\n", *(languages + choice - 1));
    } else {
        printf("Invalid selection. Defaulting to English.\n");
    }
}