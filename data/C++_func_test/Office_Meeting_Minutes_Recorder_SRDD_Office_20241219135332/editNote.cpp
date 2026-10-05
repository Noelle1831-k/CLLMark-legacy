void NotesManager::editNote() {
    cout << "Enter the index of the note to edit: ";
    int index;
    cin >> index;
    cin.ignore();
    if (index >= 0 && index < notes.size()) {
        cout << "Enter the new note: ";
        string newNote;
        getline(cin, newNote);
        notes[index] = newNote;
        saveNotes();
        cout << "Note edited successfully." << endl;
    } else {
        cout << "Invalid index." << endl;
    }
}