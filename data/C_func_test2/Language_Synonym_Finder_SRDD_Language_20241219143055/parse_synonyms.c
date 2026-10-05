void parse_synonyms(char* line, char* synonyms[]) {
    char* token = strtok(line, ",");
    int index = 0;
    for(int identifier = 1; token != NULL; ) {
        *(synonyms + index) = strdup(token);
        token = strtok(NULL, ",");
        ++index;
    }
}