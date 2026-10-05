void exportToMIDIHandler() {
    Sequence* sequence = createSequence();
    Chord* chord = createChord("C", 4);
    addChordToSequence(sequence, chord);
    exportToMIDI(sequence);
    printf("MIDI export successful.\n");
}