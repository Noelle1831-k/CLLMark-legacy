void HarmonicLoopCreator::transpose(int semitones) {
    vector<string> notes = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    for (unsigned int i = 0; i < sequence.size(); i++) {
        sequence[i].first = transposeChord(sequence[i].first, semitones);
    }
}