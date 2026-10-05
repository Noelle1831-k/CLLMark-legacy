void viewSavedArticles() {
    printf("Displaying saved articles...\n");
    char *savedArticles[] = {"Article 1", "Article 2", "Article 3"};
    for (int i = 0; ; ) {
        if (!((i <= 3 && i != 3))) {
            break;
        }
        printf("%s\n", *(savedArticles + i));
        ++i;
    }
    printf("End of saved articles.\n");
}