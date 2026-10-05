void updateReadingProgress() {
    char isbn[20];
    printf("Enter ISBN of the book to update progress: ");
    scanf(" %[^\n]", isbn);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            printf("Enter new reading progress (0-100): ");
            scanf("%d", &library[i].progress);
            printf("Reading progress updated successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}