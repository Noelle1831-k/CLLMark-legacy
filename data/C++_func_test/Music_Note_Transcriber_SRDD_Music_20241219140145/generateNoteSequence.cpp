string NoteRecognizer::generateNoteSequence(const vector<string>& notes) {
    string sequence;
    for (const string& note : notes) {
        sequence += note + " ";
    }
    return sequence;
}