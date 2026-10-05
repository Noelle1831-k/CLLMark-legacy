void listBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        printf("\nBook %d:\n", i + 1);
        printBookDetails(library[i]);
    }
}