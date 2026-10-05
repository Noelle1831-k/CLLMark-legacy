void SoundBoard::searchClip(const string& keyword) {
    cout << "Searching for sound clips with keyword: " << keyword << endl;
    for (size_t i = 0; i < clips.size(); ++i) {
        if (clips[i].getFilePath().find(keyword) != string::npos) {
            cout << "Found: " << clips[i].getFilePath() << endl;
        }
    }
}