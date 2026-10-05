Sequence* createSequence() {
    Sequence* sequence = (Sequence*)malloc(sizeof(Sequence));
    sequence->chords = NULL;
    sequence->count = 0;
    return sequence;
}