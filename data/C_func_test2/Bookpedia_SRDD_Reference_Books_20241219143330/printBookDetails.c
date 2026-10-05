void printBookDetails(Book book) {
    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("ISBN: %s\n", book.isbn);
    printf("Category: %s\n", book.category);
    printf("Tags: %s\n", book.tags);
    printf("Rating: %d\n", book.rating);
    printf("Progress: %d%%\n", book.progress);
}