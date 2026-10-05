void PhotoManager::createAlbum(const string &albumName) {
    cout << "Creating album: " << albumName << endl;
    albums.push_back(albumName);
}