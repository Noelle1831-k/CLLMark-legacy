void display_book(Book *book) {
    printf("\nBook ID: %d\n", book->id);
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Rating: %d\n", book->rating);
    printf("Notes: %s\n", book->notes);
}