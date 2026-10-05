void generate_daily_digest(NewsArticles *news, const UserPreferences *prefs, Digest *digest) {
    filter_news_by_category(news, prefs);
    sort_news(news);
    digest->count = news->count < 5 ? news->count : 5;  
    for (int i = 0; i < digest->count; i++) {
        digest->articles[i] = news->articles[i];
    }
}