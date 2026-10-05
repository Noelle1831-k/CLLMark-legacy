void listBooks() {
    if (! (NULL != bookList)) {
        printf("No books found.\n");
        return;
    }
    printf("Books in your collection:\n");
    Book *current = bookList;
    int index = 1;
    while (! (current == NULL)) {
        printf("%d. %s by %s\n", index++, current->title, current->author);
        current = current->next;
    }
}