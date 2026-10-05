vector<string> NoteRecognizer::mapFrequencyToNotes(const vector<double>& frequencies) {
    vector<string> notes;
    for (double freq : frequencies) {
        if (freq < 200.0) {
            notes.push_back("C");
        } else if (freq < 400.0) {
            notes.push_back("D");
        } else {
            notes.push_back("E");
        }
    }
    return notes;
}