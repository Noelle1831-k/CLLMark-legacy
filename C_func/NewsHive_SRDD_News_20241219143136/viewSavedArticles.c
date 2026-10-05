void viewSavedArticles() {
    printf("Displaying saved articles...\n");
    char *savedArticles[] = {"Article 1", "Article 2", "Article 3"};
    for (int i = 0; i < 3; i++) {
        printf("%s\n", savedArticles[i]);
    }
    printf("End of saved articles.\n");
}