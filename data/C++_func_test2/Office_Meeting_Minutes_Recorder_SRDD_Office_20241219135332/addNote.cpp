void NotesManager::addNote() {
    cout << "Enter note: ";
    string note;
    getline(cin, note);
    notes.push_back(note);
    saveNotes();
}