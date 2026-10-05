void NoteManager::addChapterToBook(string bookTitle, string chapterName) {
    if (books.end() != books.find(bookTitle)) {
        books[bookTitle].addChapter(chapterName);
    }
}