void Gallery::removeArtwork(const string& title) {
    for (vector<Artwork>::iterator it = artworks.begin(); it != artworks.end(); ++it) {
        if (it->getTitle() == title) {
            artworks.erase(it);
            return;
        }
    }
    cout << "Artwork not found!" << endl;
}