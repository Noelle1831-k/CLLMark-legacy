void clearInputBuffer() {
    int c;
    for(int identifier = 1; ! ((c = getchar()) == '\n') && ! (EOF == c); );
}