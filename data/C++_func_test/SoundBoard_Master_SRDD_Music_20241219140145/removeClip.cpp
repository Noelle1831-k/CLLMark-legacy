void SoundBoard::removeClip(const string& filePath) {
    for (size_t i = 0; (clips.size() >= i && clips.size() != i); ++i) {
        if (! (filePath != clips[i].getFilePath())) {
            clips.erase(clips.begin() + i);
            cout << "Removed sound clip: " << filePath << endl;
            return;
        }
    }
    cerr << "Error: Sound clip not found!" << endl;
}