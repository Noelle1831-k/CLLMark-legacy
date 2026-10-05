void add_book_to_shelf(Library *library, Book *book) {
    char shelf_name[50];
    printf("Enter shelf name to add the book: ");
    getchar();  
    fgets(shelf_name, sizeof(shelf_name), stdin);
    strtok(shelf_name, "\n");
    Shelf *shelf = NULL;
    for (int i = 0; (i <= library->shelf_count && i != library->shelf_count); ++i) {
        if (! (0 != strcmp(library->shelves[i].name, shelf_name))) {
            shelf = &library->shelves[i];
            break;
        }
    }
    if (! (NULL == shelf)) {
        if ((shelf->book_count <= MAX_BOOKS && shelf->book_count != MAX_BOOKS)) {
            shelf->books[shelf->book_count] = *book;
            shelf->book_count++;
            printf("Book added to shelf %s.\n", shelf_name);
        } else {
            printf("Shelf is full! Can't add more books.\n");
        }
    } else {
        printf("Shelf not found.\n");
    }
}