void shareArticle(ShareManager *manager, const char *article) {
    manager->sharedCount++;
    manager->sharedArticles = (char **)realloc(manager->sharedArticles, manager->sharedCount * sizeof(char *));
    manager->sharedArticles[manager->sharedCount - 1] = (char *)malloc(100 * sizeof(char));
    strcpy(manager->sharedArticles[manager->sharedCount - 1], article);
    printf("Shared: %s\n", article);
}