void generateRecommendations() {
    printf("Generating book recommendations...\n");
    if (bookCount == 0) {
        printf("No books in the library to base recommendations on.\n");
        return;
    }
    printf("Recommended Books:\n");
    for (int i = 0; i < bookCount; i++) {
        if (library[i].rating >= 4) {
            printf("- %s by %s\n", library[i].title, library[i].author);
        }
    }
}