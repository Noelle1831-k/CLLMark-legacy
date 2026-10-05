void free_news_sources(NewsSource *sources) {
    if (sources != NULL) {
        free(sources->articles);
        free(sources);
    }
}