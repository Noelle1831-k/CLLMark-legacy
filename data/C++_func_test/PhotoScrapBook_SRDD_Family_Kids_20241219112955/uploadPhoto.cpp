void PhotoManager::uploadPhoto(const string &photo) {
    cout << "Uploading photo: " << photo << endl;
    photoCollection.push_back(photo);
}