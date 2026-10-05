void addChordToSequence(Sequence* sequence, Chord* chord) {
    if (sequence && chord) {
        sequence->chords = realloc(sequence->chords, sizeof(Chord*) * (sequence->count + 1));
        sequence->chords[sequence->count] = chord;
        sequence->count++;
    }
}