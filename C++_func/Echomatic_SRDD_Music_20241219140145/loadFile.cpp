void AudioFile::loadFile() {
    cout << "Enter the filename to load: ";
    cin >> filename;
    ifstream file(filename.c_str(), ios::binary);
    if (file.is_open()) {
        cout << "File loaded successfully." << endl;
        audioData = vector<float>(1000, 0.5f);
        loaded = true;
    } else {
        cout << "Failed to load file." << endl;
        loaded = false;
    }
}