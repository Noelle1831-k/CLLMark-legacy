void fetch_news_articles(NewsSource *sources) {
    for (size_t i = 0; i < sources->count; i++) {
        printf("Title: %s\n", sources->articles[i].title);
        printf("Source: %s\n", sources->articles[i].source);
        printf("Date: %s\n", sources->articles[i].date);
        printf("Content: %s\n", sources->articles[i].content);
        printf("------------------------------\n");
    }
}