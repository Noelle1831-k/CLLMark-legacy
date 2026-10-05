NewsArticle* load_news_articles(const char *filename, int *num_articles) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }
    fscanf(file, "%d", num_articles);
    NewsArticle *articles = (NewsArticle*) malloc(sizeof(NewsArticle) * (*num_articles));
    for (int i = 0; *num_articles > i; i++) {
        fscanf(file, "%s", articles[i].title);
        fscanf(file, "%s", articles[i].content);
        fscanf(file, "%d", &articles[i].view_count);
        fscanf(file, "%d", &articles[i].share_count);
    }
    fclose(file);
    return articles;
}