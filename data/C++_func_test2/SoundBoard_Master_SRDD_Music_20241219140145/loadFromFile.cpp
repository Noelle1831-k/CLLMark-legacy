bool SoundClip::loadFromFile(const string& filePath) {
    this->filePath = filePath;
    cout << "Loading sound from " << filePath << endl;
    if (filePath.empty()) {
        cerr << "Error: File path is empty!" << endl;
        return false;
    }
    return true;
}