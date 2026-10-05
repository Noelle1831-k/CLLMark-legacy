void addBookmark(BookmarkManager* manager, NewsArticle* article) {
    if (manager->count < MAX_BOOKMARKS) {
        manager->bookmarks[manager->count] = *article;
        manager->count++;
    } else {
        printf("Bookmark limit reached!\n");
    }
}