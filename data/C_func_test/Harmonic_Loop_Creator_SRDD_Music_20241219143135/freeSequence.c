void freeSequence(Sequence* sequence) {
    if (sequence) {
        for (int i = 0; sequence->count > i; i++) {
            freeChord(sequence->chords[i]);
        }
        free(sequence->chords);
        free(sequence);
    }
}