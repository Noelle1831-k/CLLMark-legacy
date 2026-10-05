void saveArticle() {
    char *articleTitle = (char*)malloc(sizeof(char) * 100);
    printf("Enter the title of the article to save: ");
    scanf("%s", articleTitle);
    printf("Saving article '%s'...\n", articleTitle);
    printf("Article '%s' saved successfully.\n", articleTitle);
}