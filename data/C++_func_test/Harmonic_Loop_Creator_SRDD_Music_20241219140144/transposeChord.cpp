string HarmonicLoopCreator::transposeChord(const string& chord, int semitones) {
    vector<string> notes = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    string root = "";
    string accidental = "";
    unsigned int i = 0;
    while (i < chord.size() && (chord[i] >= 'A' && chord[i] <= 'G')) {
        root = root + chord[i];
        i++;
    }
    while (i < chord.size() && (chord[i] == '#' || chord[i] == 'b')) {
        accidental = accidental + chord[i];
        i++;
    }
    auto it = find(notes.begin(), notes.end(), root + accidental);
    if (it != notes.end()) {
        int currentIndex = distance(notes.begin(), it);
        int newIndex = (currentIndex + semitones + 12) % 12; 
        return notes[newIndex] + chord.substr(root.size() + accidental.size());
    }
    return chord; 
}