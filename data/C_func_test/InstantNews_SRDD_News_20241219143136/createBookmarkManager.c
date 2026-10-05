BookmarkManager* createBookmarkManager() {
    BookmarkManager* manager = malloc(sizeof(BookmarkManager));
    if (manager == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    manager->count = 0;
    return manager;
}