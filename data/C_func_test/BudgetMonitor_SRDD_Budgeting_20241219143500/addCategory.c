void addCategory() {
    if (categoryCount >= MAX_CATEGORIES) {
        printf("Category limit reached. Cannot add more categories.\n");
        return;
    }
    printf("Enter category name: ");
    if (fgets(categories[categoryCount], MAX_NAME_LENGTH, stdin) != NULL) {
        size_t len = strlen(categories[categoryCount]);
        if (len > 0 && categories[categoryCount][len - 1] == '\n') {
            categories[categoryCount][len - 1] = '\0';
        }
        categoryCount++;
        printf("Category added successfully.\n");
    } else {
        printf("Error reading category name.\n");
    }
}