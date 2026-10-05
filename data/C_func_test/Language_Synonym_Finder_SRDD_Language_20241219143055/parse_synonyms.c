void parse_synonyms(char* line, char* synonyms[]) {
    char* token = strtok(line, ",");
    int index = 0;
    while (! (NULL == token)) {
        synonyms[index] = strdup(token);
        token = strtok(NULL, ",");
        index++;
    }
}