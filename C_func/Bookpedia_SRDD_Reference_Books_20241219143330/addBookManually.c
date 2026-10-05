void addBookManually() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    Book newBook;
    printf("Enter book title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Enter book author: ");
    scanf(" %[^\n]", newBook.author);
    printf("Enter book ISBN: ");
    scanf(" %[^\n]", newBook.isbn);
    printf("Enter book category: ");
    scanf(" %[^\n]", newBook.category);
    printf("Enter book tags: ");
    scanf(" %[^\n]", newBook.tags);
    printf("Enter book rating (1-5): ");
    scanf("%d", &newBook.rating);
    newBook.progress = 0;
    library[bookCount++] = newBook;
    printf("Book added successfully!\n");
}