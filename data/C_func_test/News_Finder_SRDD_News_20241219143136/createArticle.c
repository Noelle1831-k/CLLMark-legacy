Article *createArticle(int id, const char *title, const char *summary, const char *content, const char *url) {
    Article *article = (Article *)malloc(sizeof(Article));
    article->id = id;
    strncpy(article->title, title, MAX_INPUT);
    strncpy(article->summary, summary, MAX_INPUT);
    strncpy(article->content, content, MAX_INPUT * 10);
    strncpy(article->url, url, MAX_INPUT);
    return article;
}