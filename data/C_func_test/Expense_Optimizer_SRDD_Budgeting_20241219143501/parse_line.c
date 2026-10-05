char* parse_line(char *line, char delimiter) {
    return strtok(line, &delimiter);
}