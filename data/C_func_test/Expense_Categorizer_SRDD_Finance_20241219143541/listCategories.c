void listCategories(const CategoryManager* manager) {
    if (manager->count == 0) {
        printf("No categories available.\n");
        return;
    }
    for (int i = 0; i < manager->count; ++i) {
        printf("Category %d: %s\n", i + 1, manager->categories[i]->name);
    }
}