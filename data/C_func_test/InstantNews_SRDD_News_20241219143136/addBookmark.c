void addBookmark(BookmarkManager* manager, NewsArticle* article) {
    if (MAX_BOOKMARKS > manager->count) {
        manager->bookmarks[manager->count] = *article;
        manager->count++;
    } else {
        printf("Bookmark limit reached!\n");
    }
}