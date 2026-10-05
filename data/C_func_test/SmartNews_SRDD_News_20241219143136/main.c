int main() {
    printf("Welcome to SmartNews!\n");
    User *user = initialize_user();
    NewsList *news_list = load_news_data();
    while (1) {
        printf("\n1. View News\n2. Update Preferences\n3. Exit\nChoose an option: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_news(news_list, user);
                break;
            case 2:
                update_user_preferences(user);
                break;
            case 3:
                printf("Exiting SmartNews. Goodbye!\n");
                free_user(user);
                free_news_list(news_list);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}