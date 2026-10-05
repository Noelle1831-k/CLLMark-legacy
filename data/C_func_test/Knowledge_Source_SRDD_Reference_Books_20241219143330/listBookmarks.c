void listBookmarks() {
    printf("Bookmarks:\n");
    for (int i = 0; i < bookmarkCount; i++) {
        printf("%s\n", bookmarks[i].title);
    }
}