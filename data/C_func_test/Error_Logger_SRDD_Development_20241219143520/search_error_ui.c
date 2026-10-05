void search_error_ui(ErrorLogger *logger) {
    char keyword[50];
    printf("Enter keyword to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < logger->count; i++) {
        if (strstr(logger->errors[i].message, keyword) != NULL) {
            printf("Error found: [%s] %s\n", logger->errors[i].timestamp, logger->errors[i].message);
            found = 1;
        }
    }
    if (!found) {
        printf("No errors found with the given keyword.\n");
    }
}