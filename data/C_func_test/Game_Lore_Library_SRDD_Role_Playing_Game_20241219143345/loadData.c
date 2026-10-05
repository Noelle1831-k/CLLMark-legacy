void loadData(const char *filename) {
    char *fileContent = readFile(filename);
    if (fileContent != NULL) {
        parseData(fileContent);
        free(fileContent);
    }
}