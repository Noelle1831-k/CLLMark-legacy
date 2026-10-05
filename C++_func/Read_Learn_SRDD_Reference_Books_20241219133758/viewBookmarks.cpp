void viewBookmarks() {
        vector<string> bookmarks = user.getBookmarks();
        if (bookmarks.empty()) {
            cout << "No bookmarks available." << endl;
        } else {
            cout << "Bookmarks:" << endl;
            for (size_t i = 0; i < bookmarks.size(); i++) {
                cout << bookmarks[i] << endl;
            }
        }
    }