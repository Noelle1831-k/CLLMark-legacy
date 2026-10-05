void selectLanguage() {
    printf("Select your target language:\n1. Spanish\n2. French\n3. German\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            strcpy(currentUser.targetLanguage, "Spanish");
            break;
        case 2:
            strcpy(currentUser.targetLanguage, "French");
            break;
        case 3:
            strcpy(currentUser.targetLanguage, "German");
            break;
        default:
            printf("Invalid choice. Defaulting to Spanish.\n");
            strcpy(currentUser.targetLanguage, "Spanish");
    }
}