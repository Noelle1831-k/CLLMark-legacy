void freeChordData(ChordData *chords) {
    if (chords) {
        free(chords->chords);
        free(chords);
    }
}