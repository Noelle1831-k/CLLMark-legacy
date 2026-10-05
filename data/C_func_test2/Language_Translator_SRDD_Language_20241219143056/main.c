int main() {
    char inputText[MAX_TEXT_LEN];
    char srcLang[20], destLang[20];
    int choice = 0;
    int dictionaryLoaded = 0;
    printf("Welcome to the Language Translation Software!\n");
    while (1) {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                if (!dictionaryLoaded) {
                    printf("Error: No language dictionary loaded. Please load a dictionary first.\n");
                    break;
                }
                printf("Enter source language: ");
                scanf("%s", srcLang);
                printf("Enter destination language: ");
                scanf("%s", destLang);
                printf("Enter text to translate: ");
                getchar(); 
                fgets(inputText, MAX_TEXT_LEN, stdin);
                inputText[strcspn(inputText, "\n")] = '\0'; 
                char *translation = translateText(inputText, srcLang, destLang);
                if (translation) {
                    printf("Translation: %s\n", translation);
                    free(translation);
                } else {
                    printf("Error: Translation failed or not found in the dictionary.\n");
                }
                break;
            case 2:
                if (loadDictionary()) {
                    printf("Language dictionary loaded successfully.\n");
                    dictionaryLoaded = 1;
                } else {
                    printf("Error: Failed to load language dictionary.\n");
                }
                break;
            case 3:
                if (saveDictionary()) {
                    printf("Language dictionary saved successfully.\n");
                } else {
                    printf("Error: Failed to save language dictionary.\n");
                }
                break;
            case 4:
                printf("Exiting the application. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}