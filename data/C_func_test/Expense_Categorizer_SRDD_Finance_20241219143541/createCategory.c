Category* createCategory(const char* name) {
    Category* newCategory = (Category*)malloc(sizeof(Category));
    if (newCategory == NULL) {
        fprintf(stderr, "Memory allocation failed for new category.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newCategory->name, name, sizeof(newCategory->name) - 1);
    newCategory->name[sizeof(newCategory->name) - 1] = '\0';
    newCategory->expenseCount = 0;
    return newCategory;
}