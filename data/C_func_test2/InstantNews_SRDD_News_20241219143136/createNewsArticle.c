NewsArticle createNewsArticle(char* title, char* url, char* summary) {
    NewsArticle article;
    strncpy(article.title, title, sizeof(article.title) - 1);
    article.title[sizeof(article.title) - 1] = '\0';
    strncpy(article.url, url, sizeof(article.url) - 1);
    article.url[sizeof(article.url) - 1] = '\0';
    strncpy(article.summary, summary, sizeof(article.summary) - 1);
    article.summary[sizeof(article.summary) - 1] = '\0';
    return article;
}