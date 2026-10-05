void searchArticles(ArticleDB *db, const char *query) {
    printf("Search Results for '%s':\n", query);
    for (int i = 0; i < db->size; i++) {
        if (strstr(db->articles[i]->title, query) != NULL || strstr(db->articles[i]->summary, query) != NULL) {
            printArticle(db->articles[i]);
        }
    }
}