void listNotes() {
    if (noteList == NULL) {
        printf("No notes found.\n");
        return;
    }
    printf("Notes in your collection:\n");
    Note *current = noteList;
    int index = 1;
    while (current != NULL) {
        printf("%d. %s\n", index++, current->content);
        current = current->next;
    }
}