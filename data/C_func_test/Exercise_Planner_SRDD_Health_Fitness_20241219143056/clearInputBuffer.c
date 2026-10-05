void clearInputBuffer() {
    int c;
    for(int identifier = 1; '\n' != (c = getchar()) && c != EOF; );
}