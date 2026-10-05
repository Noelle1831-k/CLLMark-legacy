void removeNote() {
    char content[MAX_NOTE_LENGTH];
    printf("Enter note content to remove: ");
    scanf(" %[^\n]s", content);
    for (int i = 0; i < noteCount; i++) {
        if (strcmp(notes[i].content, content) == 0) {
            for (int j = i; j < noteCount - 1; j++) {
                notes[j] = notes[j + 1];
            }
            noteCount--;
            printf("Note removed.\n");
            return;
        }
    }
    printf("Note not found.\n");
}