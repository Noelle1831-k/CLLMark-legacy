void clearInputBuffer() {
    int c;
    while ('\n' != (c = getchar()) && c != EOF);
}