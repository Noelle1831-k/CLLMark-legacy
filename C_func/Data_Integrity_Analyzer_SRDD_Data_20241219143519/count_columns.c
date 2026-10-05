int count_columns(const char *line) {
    int count = 0;
    const char *temp = line;
    while (*temp) {
        if (*temp == ',') count++;
        temp++;
    }
    return count + 1; 
}