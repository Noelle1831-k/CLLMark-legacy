vector<Book> searchBook(string keyword) {
        vector<Book> results;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getTitle().find(keyword) != string::npos || books[i].getAuthor().find(keyword) != string::npos) {
                results.push_back(books[i]);
            }
        }
        return results;
    }