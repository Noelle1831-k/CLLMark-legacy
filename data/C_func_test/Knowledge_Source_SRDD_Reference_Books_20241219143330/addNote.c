void addNote() {
    if (noteCount < MAX_NOTES) {
        printf("Enter note content: ");
        scanf(" %[^\n]s", notes[noteCount].content);
        noteCount++;
        printf("Note added.\n");
    } else {
        printf("Note list is full.\n");
    }
}