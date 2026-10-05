void displayChords(const ChordData *chords) {
    printf("Displaying chords...\n");
    for (size_t i = 0; i < chords->count; i++) {
        printf("Chord %zu: %s\n", i + 1, chords->chords[i]);
    }
}