void shareArticle() {
    char articleTitle[100];
    printf("Enter the title of the article to share: ");
    scanf("%s", articleTitle);
    printf("Sharing article '%s'...\n", articleTitle);
    printf("Article '%s' shared successfully.\n", articleTitle);
}