void analyzeCode(const char* fileContent, const char* fileName) {
    const char* delimiter = "\n";
    char* line = strtok(fileContent, delimiter);
    int lineNumber = 1;
    while (line != NULL) {
        if (line[0] != '\0') {  
            findDuplicates(line, fileName, lineNumber);
        }
        line = strtok(NULL, delimiter);
        lineNumber++;
    }
}