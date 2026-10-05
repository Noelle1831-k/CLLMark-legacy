void customize_preferences() {
    char choice[2];
    printf("Customization Menu:\n");
    printf("1. Set News Categories\n");
    printf("2. Set Source Preferences\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
    fgets(choice, sizeof(choice), stdin);
    if (strcmp(choice, "1\n") == 0) {
        printf("Choose a category (e.g., Technology, Politics, Environment): ");
        char category[50];
        fgets(category, sizeof(category), stdin);
        printf("You selected the category: %s", category);
    } else if (strcmp(choice, "2\n") == 0) {
        printf("Choose a source (e.g., Tech Times, Economy Today): ");
        char source[50];
        fgets(source, sizeof(source), stdin);
        printf("You selected the source: %s", source);
    } else {
        printf("Invalid choice.\n");
    }
}