void listCategories() {
    for (int i = 0; i < categoryCount; i++) {
        printf("Category %d: %s\n", i, categories[i].name);
    }
}