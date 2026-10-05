void search() {
    char keyword[100];
    printf("Enter search keyword: ");
    scanf(" %[^\n]%*c", keyword);
    printf("Searching for books and notes containing: '%s'\n", keyword);
    int found = 0;
    Book *currentBook = bookList;
    while (currentBook != NULL) {
        if (strstr(currentBook->title, keyword) || strstr(currentBook->author, keyword)) {
            printf("Found Book: %s by %s\n", currentBook->title, currentBook->author);
            found = 1;
        }
        currentBook = currentBook->next;
    }
    Note *currentNote = noteList;
    while (currentNote != NULL) {
        if (strstr(currentNote->content, keyword)) {
            printf("Found Note: %s\n", currentNote->content);
            found = 1;
        }
        currentNote = currentNote->next;
    }
    if (!found) {
        printf("No matches found for keyword: '%s'\n", keyword);
    }
}