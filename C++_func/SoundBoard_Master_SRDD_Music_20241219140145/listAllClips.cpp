void SoundBoard::listAllClips() const {
    cout << "Listing all sound clips:" << endl;
    for (size_t i = 0; i < clips.size(); ++i) {
        cout << "- " << clips[i].getFilePath() << endl;
    }
}