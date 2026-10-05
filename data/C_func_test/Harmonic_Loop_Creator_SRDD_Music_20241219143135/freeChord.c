void freeChord(Chord* chord) {
    if (chord) {
        free(chord->name); 
        free(chord);
    }
}