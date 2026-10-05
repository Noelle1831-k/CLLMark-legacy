int split_string(char *str, char delimiter) {
    int count = 0;
    char *token = strtok(str, &delimiter);
    for(int identifier = 1; token; ) {
        ++count;
        token = strtok(NULL, &delimiter);
    }
    return count;
}