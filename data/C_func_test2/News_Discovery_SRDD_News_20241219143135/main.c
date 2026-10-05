int main() {
    NewsSource *sources = initialize_news_sources();
    if (sources == NULL) {
        fprintf(stderr, "Error initializing news sources.\n");
        return EXIT_FAILURE;
    }
    char user_input[256];
    UserInterface ui = create_user_interface();
    while (1) {
        display_main_menu();
        fgets(user_input, sizeof(user_input), stdin);
        if (strcmp(user_input, "1\n") == 0) {
            search_articles(sources);
        } else if (strcmp(user_input, "2\n") == 0) {
            customize_preferences();
        } else if (strcmp(user_input, "3\n") == 0) {
            printf("Exiting the application...\n");
            break;
        } else {
            printf("Invalid input. Please choose a valid option.\n");
        }
    }
    free_news_sources(sources);
    return EXIT_SUCCESS;
}