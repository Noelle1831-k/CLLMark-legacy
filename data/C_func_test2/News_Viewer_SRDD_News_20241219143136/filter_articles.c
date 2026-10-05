void filter_articles(char **articles, const char *keyword) {
    printf("Filtering articles for keyword: %s\n", keyword);
    for (int i = 0; articles[i] != NULL; i++) {
        if (strstr(articles[i], keyword)) {
            printf("Match found: %s\n", articles[i]);
        }
    }
}