void display_dashboard(NewsArticle *articles, int num_articles, Trend *trends) {
    printf("News Insight Dashboard\n\n");
    for (int i = 0; i < num_articles; i++) {
        printf("Article: %s\n", articles[i].title);
        printf("Sentiment: %s\n", articles[i].sentiment);
        printf("Popularity Score: %d\n", articles[i].popularity_score);
        printf("Content: %s\n\n", articles[i].content);
    }
    printf("Emerging Trends:\n");
    for (int i = 0; trends[i].frequency > 0; i++) {
        printf("Trend: %s - Frequency: %d\n", trends[i].keyword, trends[i].frequency);
    }
}