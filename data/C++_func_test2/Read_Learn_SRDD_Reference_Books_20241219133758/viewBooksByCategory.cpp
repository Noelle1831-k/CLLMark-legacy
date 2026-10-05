void viewBooksByCategory() {
        string category;
        cout << "Enter category: ";
        cin.ignore();
        getline(cin, category);
        vector<Book> results = library.getBooksByCategory(category);
        if (results.empty()) {
            cout << "No books found in this category." << endl;
        } else {
            cout << "Books in Category '" << category << "':" << endl;
            for (size_t i = 0; i < results.size(); i++) {
                cout << "Title: " << results[i].getTitle() << ", Author: " << results[i].getAuthor() << endl;
            }
        }
    }