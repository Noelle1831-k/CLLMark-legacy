void NoteSequence::addNote(const string& note) {
    notes.push_back(note);
    cout << "Added note: " << note << endl;
}