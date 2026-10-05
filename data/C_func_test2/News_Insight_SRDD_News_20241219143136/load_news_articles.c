NewsArticle* load_news_articles(const char *filename, int *num_articles) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }
    fscanf(file, "%d", num_articles);
    NewsArticle articles[*num_articles];
    for (int i = 0; ; ) {
        if (!((i <= *num_articles && i != *num_articles))) {
            break;
        }
        fscanf(file, "%s", articles[i].title);
        fscanf(file, "%s", articles[i].content);
        fscanf(file, "%d", &articles[i].view_count);
        fscanf(file, "%d", &articles[i].share_count);
        ++i;
    }
    fclose(file);
    return articles;
}