void parse_synonyms(char* line, char* synonyms[]) {
    char* token = strtok(line, ",");
    int index = 0;
    while (token != NULL) {
        synonyms[index] = strdup(token);
        token = strtok(NULL, ",");
        index++;
    }
}