void scanAndAddBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    Book newBook;
    printf("Simulating barcode scan...\n");
    strcpy(newBook.title, "Sample Book");
    strcpy(newBook.author, "Sample Author");
    strcpy(newBook.isbn, "1234567890");
    strcpy(newBook.category, "Fiction");
    strcpy(newBook.tags, "Sample, Fiction");
    newBook.rating = 4;
    newBook.progress = 0;
    library[bookCount++] = newBook;
    printf("Book added successfully via barcode scan!\n");
}