void BookmarkManager::removeBookmark(User& user, const string& title) {
    vector<Article>& bookmarks = user.getBookmarks();
    for (size_t i = 0; i < bookmarks.size(); i++) {
        if (bookmarks[i].getTitle() == title) {
            bookmarks.erase(bookmarks.begin() + i);
            cout << "Removed bookmark: " << title << endl;
            return;
        }
    }
    cout << "Bookmark not found: " << title << endl;
}