void Gallery::displayByCategory(const string& category) const {
    cout << "Artworks in category: " << category << endl;
    for (vector<Artwork>::const_iterator it = artworks.begin(); it != artworks.end(); ++it) {
        if (it->getCategory() == category) {
            it->displayDetails();
            cout << "------------------------" << endl;
        }
    }
}