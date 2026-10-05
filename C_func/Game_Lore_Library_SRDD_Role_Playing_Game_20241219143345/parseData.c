void parseData(const char *rawData) {
    char *line = strtok((char *)rawData, "\n");
    while (line != NULL) {
        LoreEntry entry;
        sscanf(line, "%d|%99[^|]|%499[^|]|%49[^\n]", &entry.id, entry.title, entry.description, entry.category);
        addEntry(entry.title, entry.description, entry.category);
        line = strtok(NULL, "\n");
    }
}