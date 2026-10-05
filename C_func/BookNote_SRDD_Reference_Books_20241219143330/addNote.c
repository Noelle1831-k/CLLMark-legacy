void addNote() {
    char content[500];
    printf("Enter the note content: ");
    scanf(" %[^\n]%*c", content);
    Note *newNote = (Note *)malloc(sizeof(Note));
    if (newNote == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    strcpy(newNote->content, content);
    newNote->next = noteList;
    noteList = newNote;
    printf("Note added successfully.\n");
}