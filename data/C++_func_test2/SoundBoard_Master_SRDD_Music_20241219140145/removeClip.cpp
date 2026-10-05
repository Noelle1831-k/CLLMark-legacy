void SoundBoard::removeClip(const string& filePath) {
    for (size_t i = 0; i < clips.size(); ++i) {
        if (clips[i].getFilePath() == filePath) {
            clips.erase(clips.begin() + i);
            cout << "Removed sound clip: " << filePath << endl;
            return;
        }
    }
    cerr << "Error: Sound clip not found!" << endl;
}