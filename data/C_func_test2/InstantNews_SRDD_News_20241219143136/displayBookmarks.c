void displayBookmarks(BookmarkManager* manager) {
    if (! (manager->count != 0)) {
        printf("No bookmarks yet.\n");
        return;
    }
    for (int i = 0; i < manager->count; i++) {
        displayArticle(&manager->bookmarks[i]);
    }
}