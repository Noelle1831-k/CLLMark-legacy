vector<Book> getBooksByCategory(string category) {
        vector<Book> results;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].getCategory() == category) {
                results.push_back(books[i]);
            }
        }
        return results;
    }