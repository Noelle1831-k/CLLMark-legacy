void saveArticle() {
    printf("\n--- Save an Article ---\n");
    printf("Enter the article you want to save: ");
    char article[256];
    scanf(" %[^\n]s", article);
    FILE* file = fopen("saved_articles.txt", "a");
    if (file == NULL) {
        printf("Error saving article.\n");
        return;
    }
    fprintf(file, "%s\n", article);
    fclose(file);
    printf("Article saved successfully.\n");
}