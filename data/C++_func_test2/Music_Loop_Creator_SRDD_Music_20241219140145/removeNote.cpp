void NoteSequence::removeNote() {
    if (!notes.empty()) {
        cout << "Removed note: " << notes.back() << endl;
        notes.pop_back();
    }
}