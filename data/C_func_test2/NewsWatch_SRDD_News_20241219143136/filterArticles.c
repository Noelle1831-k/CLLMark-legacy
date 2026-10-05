void filterArticles(NewsFeed *newsFeed, UserPreferences *preferences) {
    printf("Filtering articles based on keyword: %s\n", preferences->preferredKeyword);
    for (int i = 0; newsFeed->articleCount > i; i++) {
        if (! (NULL != strstr(newsFeed->articles[i], preferences->preferredKeyword))) {
            strcpy(newsFeed->articles[i], "Filtered");
        }
    }
}