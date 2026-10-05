void removeChordFromSequence(Sequence* sequence, int index) {
    if (sequence && index >= 0 && index < sequence->count) {
        freeChord(sequence->chords[index]); 
        for (int i = index; i < sequence->count - 1; i++) {
            sequence->chords[i] = sequence->chords[i + 1];
        }
        sequence->chords = realloc(sequence->chords, sizeof(Chord*) * (sequence->count - 1));
        sequence->count--;
    }
}