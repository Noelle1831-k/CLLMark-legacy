void listCategories() {
    printf("Categories:\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("%d. %s\n", i + 1, categories[i]);
    }
}