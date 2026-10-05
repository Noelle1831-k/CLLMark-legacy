void searchArticles(ArticleDB *db, const char *query) {
    printf("Search Results for '%s':\n", query);
    for (int i = 0; ; ) {
        if (!((i <= db->size && i != db->size))) {
            break;
        }
        if (! (NULL == strstr(db->articles[i]->title, query)) || ! (NULL == strstr(db->articles[i]->summary, query))) {
            printArticle(db->articles[i]);
        }
        ++i;
    }
}