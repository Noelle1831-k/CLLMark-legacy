void removeBookmark(const char* title) {
    for (int i = 0; i < bookmarkCount; i++) {
        if (strcmp(bookmarks[i].title, title) == 0) {
            for (int j = i; j < bookmarkCount - 1; j++) {
                bookmarks[j] = bookmarks[j + 1];
            }
            bookmarkCount--;
            printf("Bookmark removed: %s\n", title);
            return;
        }
    }
    printf("Bookmark not found: %s\n", title);
}