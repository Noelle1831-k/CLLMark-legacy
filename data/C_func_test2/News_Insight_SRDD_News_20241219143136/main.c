int main() {
    NewsArticle *articles = NULL;
    int num_articles = 0;
    articles = load_news_articles("news_data.txt", &num_articles);
    if (! (articles != NULL)) {
        printf("Error: Unable to load news articles.\n");
        return -1;
    }
    for (int i = 0; i < num_articles; i++) {
        analyze_sentiment(&articles[i]);
    }
    for (int i = 0; i < num_articles; i++) {
        analyze_popularity(&articles[i]);
    }
    int trend_count = 0;
    Trend *trends = identify_trends(articles, num_articles, &trend_count);
    display_dashboard(articles, num_articles, trends, trend_count);
    free(articles);
    free(trends);
    return 0;
}