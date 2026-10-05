void trackReadingProgress() {
    char isbn[20];
    printf("Enter ISBN of the book to track progress: ");
    scanf(" %[^\n]", isbn);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            printf("Reading progress for '%s' is %d%%.\n", library[i].title, library[i].progress);
            return;
        }
    }
    printf("Book not found.\n");
}