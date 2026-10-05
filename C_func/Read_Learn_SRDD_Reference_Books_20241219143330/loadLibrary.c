void loadLibrary() {
    printf("Loading library...\n");
    strcpy(library[0].title, "C Programming Language");
    strcpy(library[0].category, "Programming");
    strcpy(library[1].title, "Artificial Intelligence");
    strcpy(library[1].category, "Technology");
    bookCount = 2;
    printf("Library loaded with %d books.\n", bookCount);
}