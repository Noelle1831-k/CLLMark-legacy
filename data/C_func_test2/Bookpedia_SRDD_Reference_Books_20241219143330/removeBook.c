void removeBook() {
    char isbn[20];
    printf("Enter ISBN of the book to remove: ");
    scanf(" %[^\n]", isbn);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("Book removed successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}