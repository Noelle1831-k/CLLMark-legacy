void visualizeDuplicates() {
    Duplicate* current = head;
    if (current == NULL) {
        printf("No duplicates to visualize.\n");
        return;
    }
    printf("Visualizing Duplicates:\n");
    while (current != NULL) {
        printf("Duplicate in File: %s at Line: %d\n", current->fileName, current->lineNumber);
        current = current->next;
    }
}