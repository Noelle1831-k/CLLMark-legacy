void AudioFile::saveFile() {
    cout << "Enter the filename to save: ";
    cin >> filename;
    ofstream file(filename.c_str(), ios::binary);
    if (file.is_open()) {
        cout << "File saved successfully." << endl;
    } else {
        cout << "Failed to save file." << endl;
    }
}