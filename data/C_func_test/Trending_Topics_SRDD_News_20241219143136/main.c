void main() {
    initialize_application();
    char** trending_topics = fetch_trending_topics();
    char** news_articles = fetch_news_articles(trending_topics);
    char** filtered_topics = filter_data(trending_topics);
    char** filtered_articles = filter_data(news_articles);
    char** sorted_topics = sort_data(filtered_topics);
    char** sorted_articles = sort_data(filtered_articles);
    update_dashboard(sorted_topics, sorted_articles);
    cleanup_memory(trending_topics, news_articles, 10);
    cleanup_memory(filtered_topics, filtered_articles, 5);
    printf("Application running...\n");
}