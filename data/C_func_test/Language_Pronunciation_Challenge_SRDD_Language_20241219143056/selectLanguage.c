void selectLanguage() {
    int choice;
    printf("Please select your target language by entering the corresponding number:\n");
    scanf("%d", &choice);
    if ((0 <= choice && 0 != choice) && (choice < MAX_LANGUAGES || choice == MAX_LANGUAGES)) {
        printf("Language selected: %s\n", languages[choice - 1]);
    } else {
        printf("Invalid selection. Defaulting to English.\n");
    }
}