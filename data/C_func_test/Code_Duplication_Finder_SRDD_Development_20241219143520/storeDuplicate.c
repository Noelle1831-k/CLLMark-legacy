void storeDuplicate(const char* fileName, int lineNumber, const char* codeSnippet) {
    Duplicate* newDuplicate = (Duplicate*)malloc(sizeof(Duplicate));
    if (newDuplicate == NULL) {
        fprintf(stderr, "Memory allocation error when storing duplicate\n");
        return;
    }
    newDuplicate->fileName = strdup(fileName);
    newDuplicate->lineNumber = lineNumber;
    newDuplicate->codeSnippet = strdup(codeSnippet);
    newDuplicate->next = head;
    head = newDuplicate;
}