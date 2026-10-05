int main() {
    printf("Welcome to NewsHive!\n");
    initializePreferences();
    while (1) {
        int choice;
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                fetchNews();
                break;
            case 2:
                viewSavedArticles();
                break;
            case 3:
                shareArticle();
                break;
            case 4:
                bookmarkSource();
                break;
            case 5:
                printf("Exiting NewsHive. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}