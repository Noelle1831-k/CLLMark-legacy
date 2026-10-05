void addArticle(ArticleDB *db, Article *article) {
    if (db->size == db->capacity) {
        db->capacity *= 2;
        db->articles = (Article **)realloc(db->articles, sizeof(Article *) * db->capacity);
    }
    db->articles[db->size++] = article;
}