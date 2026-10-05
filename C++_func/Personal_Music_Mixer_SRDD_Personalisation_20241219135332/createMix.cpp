void Mixer::createMix() {
    vector<string> songs = playlist.getPlaylist();
    for (size_t i = 0; i < songs.size(); ++i) {
        processor.adjustVolume(songs[i], 5);
        if (i < songs.size() - 1) {
            processor.applyCrossfade(songs[i], songs[i + 1]);
        }
        processor.applyFadeIn(songs[i]);
        processor.applyFadeOut(songs[i]);
    }
    cout << "Mix created successfully!" << endl;
}