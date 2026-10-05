void Scale::generateScale() {
    notes.clear();
    notes.push_back(rootNote);
    double currentFrequency = rootNote.getFrequency();
    int currentOctave = rootNote.getOctave();
    string noteNames[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    int rootNoteIndex = find(noteNames, noteNames + 12, rootNote.getName()) - noteNames;
    for (int i = 0; i < intervals.size(); ++i) {
        int semitoneOffset = intervals[i];
        int noteIndex = (rootNoteIndex + semitoneOffset) % 12;
        currentOctave += (rootNoteIndex + semitoneOffset) / 12;
        string noteName = noteNames[noteIndex];
        Note newNote(noteName, currentOctave);
        notes.push_back(newNote);
    }
}