void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            processNews();
            break;
        case 2:
            customizePreferences();
            break;
        case 3:
            saveArticle();
            break;
        case 4:
            shareArticle();
            break;
        case 5:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}