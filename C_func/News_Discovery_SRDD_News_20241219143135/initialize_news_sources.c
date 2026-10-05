NewsSource *initialize_news_sources() {
    NewsSource *sources = malloc(sizeof(NewsSource));
    if (sources == NULL) {
        return NULL;
    }
    sources->count = 3; 
    sources->articles = malloc(sources->count * sizeof(NewsArticle));
    if (sources->articles == NULL) {
        free(sources);
        return NULL;
    }
    strcpy(sources->articles[0].title, "Tech World Advancements");
    strcpy(sources->articles[0].source, "Tech Times");
    strcpy(sources->articles[0].date, "2024-12-01");
    strcpy(sources->articles[0].content, "Latest trends in artificial intelligence...");
    strcpy(sources->articles[1].title, "Global Economy Update");
    strcpy(sources->articles[1].source, "Economy Today");
    strcpy(sources->articles[1].date, "2024-12-02");
    strcpy(sources->articles[1].content, "A look into the recent shifts in global markets...");
    strcpy(sources->articles[2].title, "Climate Change and Sustainability");
    strcpy(sources->articles[2].source, "Environment News");
    strcpy(sources->articles[2].date, "2024-12-03");
    strcpy(sources->articles[2].content, "The latest reports on environmental sustainability...");
    return sources;
}