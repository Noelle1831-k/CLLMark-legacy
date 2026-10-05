bool AudioProcessor::loadFile(string filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Failed to open file: " << filename << endl;
        return false;
    }
    for (int i = 0; i < 1000; i++) {
        audioData.push_back(sin(i * 0.01)); 
    }
    file.close();
    return true;
}