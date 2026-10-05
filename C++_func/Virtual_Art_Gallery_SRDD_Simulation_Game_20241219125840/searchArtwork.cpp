Artwork* Gallery::searchArtwork(const string& title) {
    for (vector<Artwork>::iterator it = artworks.begin(); it != artworks.end(); ++it) {
        if (it->getTitle() == title) {
            return &(*it);
        }
    }
    return nullptr;
}