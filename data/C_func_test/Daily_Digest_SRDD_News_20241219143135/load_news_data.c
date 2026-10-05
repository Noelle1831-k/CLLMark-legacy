void load_news_data(NewsArticles *news) {
    strcpy(news->articles[0].title, "Breaking News: Global Stock Markets Crash");
    strcpy(news->articles[0].category, "Finance");
    news->articles[0].timestamp = 1612569810;
    strcpy(news->articles[1].title, "Tech Innovation: AI Changing the Future");
    strcpy(news->articles[1].category, "Technology");
    news->articles[1].timestamp = 1612572910;
    strcpy(news->articles[2].title, "Sports Update: The Olympics Are Coming");
    strcpy(news->articles[2].category, "Sports");
    news->articles[2].timestamp = 1612589810;
    news->count = 3;
}