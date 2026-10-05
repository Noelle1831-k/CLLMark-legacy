bool AudioProcessor::loadAudioFile(const string& filePath) {
    loadedFilePath = filePath;
    ifstream file(filePath.c_str());
    if (!file) {
        cerr << "Error: File not found or inaccessible." << endl;
        return false;
    }
    file.close();
    cout << "Loading audio file: " << filePath << endl;
    return true;
}