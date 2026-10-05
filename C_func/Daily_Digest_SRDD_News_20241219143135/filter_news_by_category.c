void filter_news_by_category(NewsArticles *news, const UserPreferences *prefs) {
    NewsArticles filteredNews;
    int i, j = 0;
    for (i = 0; i < news->count; i++) {
        if (strcmp(news->articles[i].category, prefs->preferred_category) == 0) {
            filteredNews.articles[j] = news->articles[i];
            j++;
        }
    }
    filteredNews.count = j;
    *news = filteredNews;  
}