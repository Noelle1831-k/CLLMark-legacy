void Gallery::displayGallery() const {
    cout << "Gallery: " << name << " | Location: " << location << endl;
    cout << "Artworks:" << endl;
    for (vector<Artwork>::const_iterator it = artworks.begin(); it != artworks.end(); ++it) {
        it->displayDetails();
        cout << "------------------------" << endl;
    }
}