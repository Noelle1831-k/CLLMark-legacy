ArticleDB *createArticleDB() {
    ArticleDB *db = (ArticleDB *)malloc(sizeof(ArticleDB));
    db->articles = (Article **)malloc(sizeof(Article *) * 10);  
    db->size = 0;
    db->capacity = 10;
    return db;
}