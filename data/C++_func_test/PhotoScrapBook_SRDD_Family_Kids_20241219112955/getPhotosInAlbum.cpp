vector<string> PhotoManager::getPhotosInAlbum(const string &albumName) const {
    vector<string> photosInAlbum;
    for (size_t i = 0; photoCollection.size() > i; i++) {
        photosInAlbum.push_back(photoCollection[i]);
    }
    return photosInAlbum;
}