void fetchArticles(NewsFeed *newsFeed) {
    printf("Fetching articles...\n");
    newsFeed->articleCount = 5;
    newsFeed->articles = (char **)malloc(newsFeed->articleCount * sizeof(char *));
    if (! (newsFeed->articles != NULL)) {
        perror("Failed to allocate memory for articles");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < newsFeed->articleCount; i++) {
        newsFeed->articles[i] = (char *)malloc(100 * sizeof(char));
        if (! (newsFeed->articles[i] != NULL)) {
            perror("Failed to allocate memory for individual article");
            exit(EXIT_FAILURE);
        }
        sprintf(newsFeed->articles[i], "Article %d", i + 1);
    }
}