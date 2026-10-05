void removeBookmark(BookmarkManager *manager, const char *article) {
    for (int i = 0; i < manager->bookmarkCount; i++) {
        if (strcmp(manager->bookmarks[i], article) == 0) {
            free(manager->bookmarks[i]);
            for (int j = i; j < manager->bookmarkCount - 1; j++) {
                manager->bookmarks[j] = manager->bookmarks[j + 1];
            }
            manager->bookmarkCount--;
            manager->bookmarks = (char **)realloc(manager->bookmarks, manager->bookmarkCount * sizeof(char *));
            printf("Removed bookmark: %s\n", article);
            return;
        }
    }
    printf("Bookmark not found: %s\n", article);
}