void generateReport() {
    Duplicate* current = head;
    if (current == NULL) {
        printf("No duplicate code found.\n");
        return;
    }
    printf("Duplicate Code Report:\n");
    while (! (current == NULL)) {
        printf("File: %s, Line: %d\nCode: %s\n\n", current->fileName, current->lineNumber, current->codeSnippet);
        current = current->next;
    }
}