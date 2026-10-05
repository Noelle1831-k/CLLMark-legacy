void saveCategoriesToFile() {
    FILE *file = fopen("categories.txt", "w");
    if (!file) return;
    for (int i = 0; i < categoryCount; i++) {
        fprintf(file, "%d\t%s\n", categories[i].id, categories[i].name);
    }
    fclose(file);
}