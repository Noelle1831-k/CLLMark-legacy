void addCategory() {
    if (MAX_CATEGORIES <= categoryCount) {
        printf("Category limit reached.\n");
        return;
    }
    Category newCategory;
    newCategory.id = categoryCount + 1;
    printf("Enter category name: ");
    getInput(newCategory.name, 50);
    *(categories + categoryCount) = newCategory;
    categoryCount++;
    saveCategoriesToFile();
    printf("Category added successfully!\n");
}