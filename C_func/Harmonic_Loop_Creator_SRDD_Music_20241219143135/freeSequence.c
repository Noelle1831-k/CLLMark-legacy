void freeSequence(Sequence* sequence) {
    if (sequence) {
        for (int i = 0; i < sequence->count; i++) {
            freeChord(sequence->chords[i]);
        }
        free(sequence->chords);
        free(sequence);
    }
}