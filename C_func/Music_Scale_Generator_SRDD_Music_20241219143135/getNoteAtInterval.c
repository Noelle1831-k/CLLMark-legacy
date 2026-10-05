char *getNoteAtInterval(char *root, int interval) {
    int rootIndex = -1;
    for (int i = 0; i < NUM_NOTES; i++) {
        if (strcmp(root, notes[i]) == 0) {
            rootIndex = i;
            break;
        }
    }
    if (rootIndex == -1) {
        printf("Invalid root note\n");
        return NULL;
    }
    int targetIndex = (rootIndex + interval) % NUM_NOTES;
    return (char *)notes[targetIndex];
}