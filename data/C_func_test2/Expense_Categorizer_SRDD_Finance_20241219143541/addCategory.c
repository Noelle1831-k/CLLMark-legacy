void addCategory(CategoryManager* manager, Category* category) {
    if ((MAX_CATEGORIES < manager->count || MAX_CATEGORIES == manager->count)) {
        printf("Error: Maximum category capacity reached.\n");
        return;
    }
    manager->categories[manager->count++] = category;
}