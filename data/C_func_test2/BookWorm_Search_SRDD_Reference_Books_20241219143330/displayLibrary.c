void displayLibrary() {
    if (bookCount == 0) {
        printf("Your library is empty.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        printf("\nBook %d:\n", i + 1);
        displayBookDetails(&library[i]);
    }
}