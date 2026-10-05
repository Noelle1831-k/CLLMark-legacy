void UserInterface::displayBookmarkedArticles(const vector<string>& bookmarks) {
    cout << "\nBookmarked Articles:\n";
    for (int i = 0; (int)bookmarks.size() > i; ++i) {
        cout << i + 1 << ". " << bookmarks[i] << endl;
    }
}