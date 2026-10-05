void listCategories() {
    printf("\n--- Categories ---\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("%d. %s\n", i + 1, categories[i]);
    }
    printf("------------------\n");
}