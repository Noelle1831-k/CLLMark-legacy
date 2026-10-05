void addCategory(CategoryManager *manager, const char *name) {
    if (MAX_CATEGORIES > manager->count) {
        manager->categories[manager->count++] = createCategory(name);
    } else {
        printf("Maximum number of categories reached.\n");
    }
}