Book createBook(const char *title, const char *author, const char *summary, const char *coverImage) {
    Book book;
    strncpy(book.title, title, sizeof(book.title) - 1);
    strncpy(book.author, author, sizeof(book.author) - 1);
    strncpy(book.summary, summary, sizeof(book.summary) - 1);
    strncpy(book.coverImage, coverImage, sizeof(book.coverImage) - 1);
    return book;
}