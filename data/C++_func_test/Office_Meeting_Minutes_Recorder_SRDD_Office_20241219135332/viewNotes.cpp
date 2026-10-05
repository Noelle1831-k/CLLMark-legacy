void NotesManager::viewNotes() {
    cout << "Notes:" << endl;
    for (size_t i = 0; i < notes.size(); i++) {
        cout << i + 1 << ". " << notes[i] << endl;
    }
}