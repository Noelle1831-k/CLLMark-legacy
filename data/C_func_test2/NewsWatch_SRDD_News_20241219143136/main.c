int main() {
    NewsFeed newsFeed;
    UserPreferences userPreferences;
    BookmarkManager bookmarkManager = {NULL, 0};  
    ShareManager shareManager = {NULL, 0};  
    loadPreferences(&userPreferences);
    fetchArticles(&newsFeed);
    filterArticles(&newsFeed, &userPreferences);
    sortTrending(&newsFeed);
    printf("Curated News Feed:\n");
    displayArticles(&newsFeed);
    addBookmark(&bookmarkManager, "Article 1");
    shareArticle(&shareManager, "Article 1");
    savePreferences(&userPreferences);
    for (int i = 0; i < newsFeed.articleCount; i++) {
        free(newsFeed.articles[i]);
    }
    free(newsFeed.articles);
    for (int i = 0; i < bookmarkManager.bookmarkCount; i++) {
        free(bookmarkManager.bookmarks[i]);
    }
    free(bookmarkManager.bookmarks);
    for (int i = 0; i < shareManager.sharedCount; i++) {
        free(shareManager.sharedArticles[i]);
    }
    free(shareManager.sharedArticles);
    return 0;
}