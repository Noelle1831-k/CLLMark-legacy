void BookmarkManager::displayBookmarks(const User& user) const {
    vector<Article> bookmarks = user.getBookmarks();
    for (size_t i = 0; i < bookmarks.size(); i++) {
        cout << "Bookmark " << i + 1 << ": " << bookmarks[i].getTitle() << endl;
    }
}