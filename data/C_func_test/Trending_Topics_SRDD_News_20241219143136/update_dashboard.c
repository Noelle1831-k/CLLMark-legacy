void update_dashboard(char** topics, char** articles) {
    printf("Updating dashboard with new data...\n");
    display_trending_topics(topics);
    display_news_articles(articles);
}