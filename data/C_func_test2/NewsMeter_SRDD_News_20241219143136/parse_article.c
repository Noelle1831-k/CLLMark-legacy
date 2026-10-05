Article parse_article(const char *input) {
    Article article;
    memset(&article, 0, sizeof(Article));
    if (strstr(input, "http") != NULL) {
        strcpy(article.source, "example.com");
        strcpy(article.title, "Example News Title");
        strcpy(article.content, "This is an example article content.");
        article.valid = 1;
    } else {
        strcpy(article.source, "unknown");
        strcpy(article.content, input);
        article.valid = 1;
    }
    strcpy(article.author, "John Doe");
    strcpy(article.publication_date, "2023-10-01");
    return article;
}