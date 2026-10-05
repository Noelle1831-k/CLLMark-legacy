bool AudioProcessor::loadAudioFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error loading audio file: " << filename << endl;
        return false;
    }
    cout << "Audio file loaded successfully: " << filename << endl;
    file.close();
    return true;
}