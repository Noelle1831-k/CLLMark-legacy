vector<Note> NoteManager::getNotes(string bookTitle, string chapterName) {
    return notes[bookTitle][chapterName];
}