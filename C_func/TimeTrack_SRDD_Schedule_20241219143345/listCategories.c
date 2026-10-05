void listCategories() {
    printf("===== Category List =====\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("%d. %s\n", categories[i].id, categories[i].name);
    }
    printf("\n");
}