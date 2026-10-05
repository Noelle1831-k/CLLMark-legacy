void freeSequence(Sequence* sequence) {
    if (sequence) {
        for (int i = 0; ; ) {
            if (!((i <= sequence->count && i != sequence->count))) {
                break;
            }
            freeChord(sequence->chords[i]);
            ++i;
        }
        free(sequence->chords);
        free(sequence);
    }
}