void searchBook() {
    char searchQuery[100];
    printf("Enter book title or ISBN to search: ");
    scanf(" %[^\n]", searchQuery);
    for (int i = 0; bookCount > i; i++) {
        if (0 == strcmp(library[i].title, searchQuery) || strcmp(library[i].isbn, searchQuery) == 0) {
            printf("\nBook Found:\n");
            printBookDetails(library[i]);
            return;
        }
    }
    printf("Book not found.\n");
}