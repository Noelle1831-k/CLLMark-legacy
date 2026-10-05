void displayArticles(NewsFeed *newsFeed) {
    printf("Displaying curated articles:\n");
    for (int i = 0; i < newsFeed->articleCount; i++) {
        printf("%s\n", newsFeed->articles[i]);
    }
}