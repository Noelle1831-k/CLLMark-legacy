void display_news_articles(char** articles) {
    printf("\n--- News Articles ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, articles[i]);
    }
}