void NoteManager::addChapterToBook(string bookTitle, string chapterName) {
    if (books.find(bookTitle) != books.end()) {
        books[bookTitle].addChapter(chapterName);
    }
}