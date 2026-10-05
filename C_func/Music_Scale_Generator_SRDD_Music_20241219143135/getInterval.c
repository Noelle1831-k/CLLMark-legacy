int getInterval(char *note1, char *note2) {
    int index1 = -1, index2 = -1;
    for (int i = 0; i < NUM_NOTES; i++) {
        if (strcmp(note1, notes[i]) == 0) {
            index1 = i;
        }
        if (strcmp(note2, notes[i]) == 0) {
            index2 = i;
        }
    }
    if (index1 == -1 || index2 == -1) {
        printf("Invalid notes\n");
        return -1;
    }
    return (index2 - index1 + NUM_NOTES) % NUM_NOTES;
}