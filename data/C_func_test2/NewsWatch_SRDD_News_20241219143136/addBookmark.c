void addBookmark(BookmarkManager *manager, const char *article) {
    manager->bookmarkCount++;
    manager->bookmarks = (char **)realloc(manager->bookmarks, manager->bookmarkCount * sizeof(char *));
    manager->bookmarks[manager->bookmarkCount - 1] = (char *)malloc(100 * sizeof(char));
    strcpy(manager->bookmarks[manager->bookmarkCount - 1], article);
    printf("Bookmarked: %s\n", article);
}