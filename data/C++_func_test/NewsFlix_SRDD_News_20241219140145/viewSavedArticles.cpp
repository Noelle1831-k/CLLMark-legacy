void User::viewSavedArticles() const {
    cout << "Saved Articles:" << endl;
    for (size_t i = 0; i < savedArticles.size(); ++i) {
        cout << savedArticles[i].getTitle() << endl;
    }
}