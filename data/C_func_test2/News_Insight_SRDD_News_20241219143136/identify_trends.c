Trend* identify_trends(NewsArticle *articles, int num_articles) {
    Trend *trends = (Trend*) malloc(sizeof(Trend) * num_articles);
    int trend_count = 0;
    for (int i = 0; i < num_articles; i++) {
        if (strstr(articles[i].content, "technology") != NULL) {
            strcpy(trends[trend_count].keyword, "Technology");
            trends[trend_count].frequency++;
            trend_count++;
        }
    }
    return trends;
}