void displayChords(const ChordData *chords) {
    printf("Displaying chords...\n");
    for (size_t i = 0; ; ) {
        if (!((i <= chords->count && i != chords->count))) {
            break;
        }
        printf("Chord %zu: %s\n", i + 1, chords->chords[i]);
        ++i;
    }
}