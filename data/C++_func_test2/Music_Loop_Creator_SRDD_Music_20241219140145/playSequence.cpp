void NoteSequence::playSequence() {
    cout << "Playing sequence: ";
    for (size_t i = 0; i < notes.size(); i++) {
        cout << notes[i] << " ";
    }
    cout << endl;
}