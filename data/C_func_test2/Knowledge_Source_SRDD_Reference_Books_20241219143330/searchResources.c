void searchResources() {
    char query[MAX_TITLE_LENGTH];
    printf("Enter search query: ");
    scanf("%s", query);
    printf("Searching resources...\n");
    for (int i = 0; i < resourceCount; i++) {
        if (strstr(resources[i].title, query) != NULL) {
            printf("Found: %s\n", resources[i].title);
        }
    }
}