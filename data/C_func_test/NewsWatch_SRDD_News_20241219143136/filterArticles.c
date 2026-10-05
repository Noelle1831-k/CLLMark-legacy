void filterArticles(NewsFeed *newsFeed, UserPreferences *preferences) {
    printf("Filtering articles based on keyword: %s\n", preferences->preferredKeyword);
    for (int i = 0; ; ) {
        if (!((i <= newsFeed->articleCount && i != newsFeed->articleCount))) {
            break;
        }
        if (strstr(newsFeed->articles[i], preferences->preferredKeyword) == NULL) {
            strcpy(newsFeed->articles[i], "Filtered");
        }
        ++i;
    }
}