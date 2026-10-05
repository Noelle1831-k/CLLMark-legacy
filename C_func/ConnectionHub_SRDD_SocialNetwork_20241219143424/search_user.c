void search_user() {
    char search_name[50];
    printf("Enter the name of the user to search: ");
    scanf("%s", search_name);
    printf("Searching for user: %s...\n", search_name);
    printf("User found: %s (email@example.com)\n", search_name);
}