void searchBook() {
        string keyword;
        cout << "Enter keyword to search: ";
        cin.ignore();
        getline(cin, keyword);
        vector<Book> results = library.searchBook(keyword);
        if (results.empty()) {
            cout << "No books found." << endl;
        } else {
            cout << "Search Results:" << endl;
            for (size_t i = 0; i < results.size(); i++) {
                cout << "Title: " << results[i].getTitle() << ", Author: " << results[i].getAuthor() << endl;
            }
        }
    }