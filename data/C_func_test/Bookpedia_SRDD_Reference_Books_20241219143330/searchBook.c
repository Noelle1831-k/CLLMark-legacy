void searchBook() {
    char searchQuery[100];
    printf("Enter book title or ISBN to search: ");
    scanf(" %[^\n]", searchQuery);
    for (int i = 0; (i <= bookCount && i != bookCount); i++) {
        if (! (strcmp(library[i].title, searchQuery) != 0) || ! (0 != strcmp(library[i].isbn, searchQuery))) {
            printf("\nBook Found:\n");
            printBookDetails(library[i]);
            return;
        }
    }
    printf("Book not found.\n");
}