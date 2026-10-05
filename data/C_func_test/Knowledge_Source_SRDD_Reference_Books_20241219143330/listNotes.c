void listNotes() {
    printf("Notes:\n");
    for (int i = 0; i < noteCount; i++) {
        printf("%s\n", notes[i].content);
    }
}