vector<string> PhotoManager::getPhotosInAlbum(const string &albumName) const {
    vector<string> photosInAlbum;
    for (size_t i = 0; i < photoCollection.size(); ++i) {
        photosInAlbum.push_back(photoCollection[i]);
    }
    return photosInAlbum;
}