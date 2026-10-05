bool AudioProcessor::loadAudioFile(const string& filePath) {
    ifstream file(filePath, ios::binary);
    if (!file) {
        cerr << "Error: Unable to open file at " << filePath << endl;
        return false;
    }
    audioData.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return true;
}