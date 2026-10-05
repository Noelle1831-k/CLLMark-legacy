void destroyArticleDB(ArticleDB *db) {
    for (int i = 0; i < db->size; i++) {
        destroyArticle(db->articles[i]);
    }
    free(db->articles);
    free(db);
}