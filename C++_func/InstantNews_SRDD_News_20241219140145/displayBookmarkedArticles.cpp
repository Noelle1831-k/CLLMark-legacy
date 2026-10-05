void UserInterface::displayBookmarkedArticles(const vector<string>& bookmarks) {
    cout << "\nBookmarked Articles:\n";
    for (int i = 0; i < (int)bookmarks.size(); i++) {
        cout << i + 1 << ". " << bookmarks[i] << endl;
    }
}