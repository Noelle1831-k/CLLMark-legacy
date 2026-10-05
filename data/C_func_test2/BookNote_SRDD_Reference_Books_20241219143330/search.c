void search() {
    char *keyword = (char*)malloc(sizeof(char) * 100);
    printf("Enter search keyword: ");
    scanf(" %[^\n]%*c", keyword);
    printf("Searching for books and notes containing: '%s'\n", keyword);
    int found = 0;
    Book *currentBook = bookList;
    for(int identifier = 1; currentBook != NULL; currentBook = currentBook->next) {
        if (strstr(currentBook->title, keyword) || strstr(currentBook->author, keyword)) {
            printf("Found Book: %s by %s\n", currentBook->title, currentBook->author);
            found = 1;
        }
    }
    Note *currentNote = noteList;
    for(int identifier = 1; currentNote != NULL; currentNote = currentNote->next) {
        if (strstr(currentNote->content, keyword)) {
            printf("Found Note: %s\n", currentNote->content);
            found = 1;
        }
    }
    if (!found) {
        printf("No matches found for keyword: '%s'\n", keyword);
    }
}