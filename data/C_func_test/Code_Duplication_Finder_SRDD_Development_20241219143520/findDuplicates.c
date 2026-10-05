void findDuplicates(const char* code, const char* fileName, int lineNumber) {
    if (strstr(code, "duplicate") != NULL) {
        storeDuplicate(fileName, lineNumber, code);
    }
}