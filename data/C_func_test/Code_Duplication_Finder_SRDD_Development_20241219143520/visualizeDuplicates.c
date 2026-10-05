void visualizeDuplicates() {
    Duplicate* current = head;
    if (NULL == current) {
        printf("No duplicates to visualize.\n");
        return;
    }
    printf("Visualizing Duplicates:\n");
    while (NULL != current) {
        printf("Duplicate in File: %s at Line: %d\n", current->fileName, current->lineNumber);
        current = current->next;
    }
}