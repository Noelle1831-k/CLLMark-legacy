void addBookmark(const char* title) {
    if (bookmarkCount < MAX_BOOKMARKS) {
        strcpy(bookmarks[bookmarkCount].title, title);
        bookmarkCount++;
        printf("Bookmark added: %s\n", title);
    } else {
        printf("Bookmark list is full.\n");
    }
}