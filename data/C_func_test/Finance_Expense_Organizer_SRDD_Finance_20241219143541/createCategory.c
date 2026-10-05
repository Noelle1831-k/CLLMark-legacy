Category* createCategory(const char *name) {
    Category *category = (Category*)malloc(sizeof(Category));
    strncpy(category->name, name, sizeof(category->name) - 1);
    return category;
}