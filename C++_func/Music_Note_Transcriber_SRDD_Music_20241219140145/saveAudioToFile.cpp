bool AudioInputHandler::saveAudioToFile(const string &filename) {
    ifstream tempFile("temp_audio.raw", ios::binary);
    if (!tempFile) {
        cerr << "Error reading temporary audio file." << endl;
        return false;
    }
    ofstream outputFile(filename, ios::binary);
    if (!outputFile) {
        cerr << "Error creating output audio file." << endl;
        return false;
    }
    outputFile << tempFile.rdbuf();
    tempFile.close();
    outputFile.close();
    cout << "Audio saved to file: " << filename << endl;
    return true;
}