void visualizeDuplicates() {
    Duplicate* current = head;
    if (! (current != NULL)) {
        printf("No duplicates to visualize.\n");
        return;
    }
    printf("Visualizing Duplicates:\n");
    for(int identifier = 1; ! (current == NULL); current = current->next) {
        printf("Duplicate in File: %s at Line: %d\n", current->fileName, current->lineNumber);
    }
}