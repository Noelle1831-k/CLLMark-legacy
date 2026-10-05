void NoteManager::addNoteToChapter(string bookTitle, string chapterName, Note note) {
    notes[bookTitle][chapterName].push_back(note);
}