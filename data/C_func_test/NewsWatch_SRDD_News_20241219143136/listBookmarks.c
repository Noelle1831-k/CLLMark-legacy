void listBookmarks(BookmarkManager *manager) {
    printf("Bookmarks:\n");
    for (int i = 0; i < manager->bookmarkCount; i++) {
        printf("%s\n", manager->bookmarks[i]);
    }
}