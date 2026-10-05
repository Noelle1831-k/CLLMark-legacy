void browseCategories() {
    printf("Browsing categories...\n");
    char categories[MAX_BOOKS][MAX_CATEGORY_LENGTH];
    int categoryCount = 0;
    for (int i = 0; i < bookCount; i++) {
        int exists = 0;
        for (int j = 0; j < categoryCount; j++) {
            if (strcasecmp(categories[j], library[i].category) == 0) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            strcpy(categories[categoryCount], library[i].category);
            categoryCount++;
        }
    }
    printf("Available categories:\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("- %s\n", categories[i]);
    }
}