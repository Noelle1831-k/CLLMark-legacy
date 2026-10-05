int count_tokens(char **tokens) {
    int count = 0;
    while (tokens[count] != NULL) {
        count++;
    }
    return count;
}