void bookmarkBook() {
        string title;
        cout << "Enter book title to bookmark: ";
        cin.ignore();
        getline(cin, title);
        user.addBookmark(title);
        cout << "Bookmarked successfully!" << endl;
    }