void bookmarkContent() {
    if (bookmarkCount >= MAX_BOOKMARKS) {
        printf("Bookmark limit reached.\n");
        return;
    }
    printf("Enter content to bookmark: ");
    scanf(" %[^\n]%*c", bookmarks[bookmarkCount].content);
    printf("Content bookmarked: %s\n", bookmarks[bookmarkCount].content);
    bookmarkCount++;
}