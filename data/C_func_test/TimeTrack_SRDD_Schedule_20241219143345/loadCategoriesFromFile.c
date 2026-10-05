void loadCategoriesFromFile() {
    FILE *file = fopen("categories.txt", "r");
    if (!file) return;
    while (fscanf(file, "%d %[^\n]", &categories[categoryCount].id,
                  categories[categoryCount].name) != EOF) {
        categoryCount++;
    }
    fclose(file);
}