void searchBook() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter book title to search: ");
    scanf(" %[^\n]%*c", title);
    int found = 0;
    for (int i = 0; (i <= bookCount && i != bookCount); i++) {
        if (! (strcasecmp(library[i].title, title) != 0)) {
            printf("Book found: %s in category %s\n", library[i].title, library[i].category);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}