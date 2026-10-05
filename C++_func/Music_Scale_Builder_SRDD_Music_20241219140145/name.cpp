Note::Note(string noteName, int noteOctave) : name(noteName), octave(noteOctave) {
    calculateFrequency();
}