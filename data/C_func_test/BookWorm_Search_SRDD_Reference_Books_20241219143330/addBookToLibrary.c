void addBookToLibrary(const char *title, const char *author, const char *summary) {
    if (bookCount >= MAX_BOOKS) {
        printf("Error: Library is full. Cannot add more books.\n");
        return;
    }
    library[bookCount] = createBook(title, author, summary, "No Cover Image");
    bookCount++;
    printf("Book added successfully!\n");
}