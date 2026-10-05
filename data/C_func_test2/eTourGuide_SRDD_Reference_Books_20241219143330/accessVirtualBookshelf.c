void accessVirtualBookshelf() {
    printf("\nVirtual Bookshelf\n");
    char *books[] = {"1984 by George Orwell", "To Kill a Mockingbird by Harper Lee", "Pride and Prejudice by Jane Austen"};
    int numBooks = sizeof(books) / sizeof(books[0]);
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s\n", i + 1, books[i]);
    }
    printf("Select a book to read a summary: ");
    int choice = getUserChoice();
    if (0 < choice && choice <= numBooks) {
        printf("Displaying summary of %s...\n", books[choice - 1]);
        simulateLoading();
    } else {
        printf("Invalid choice. Returning to main menu.\n");
    }
}