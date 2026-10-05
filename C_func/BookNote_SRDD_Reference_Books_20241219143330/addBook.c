void addBook() {
    char title[100], author[100];
    printf("Enter book title: ");
    scanf(" %[^\n]%*c", title);
    printf("Enter book author: ");
    scanf(" %[^\n]%*c", author);
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = bookList;
    bookList = newBook;
    printf("Book added successfully: %s by %s\n", title, author);
}