void save_article(const char *title) {
    FILE *file = fopen("saved_articles.txt", "a");
    if (!file) {
        printf("Error: Unable to save the article.\n");
        return;
    }
    fprintf(file, "Saved Article: %s\n", title);
    fclose(file);
    printf("Article saved successfully!\n");
}