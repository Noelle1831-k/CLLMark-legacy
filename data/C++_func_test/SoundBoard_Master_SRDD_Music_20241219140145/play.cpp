void SoundClip::play() const {
    if (filePath.empty()) {
        cerr << "Error: No sound file loaded!" << endl;
        return;
    }
    cout << "Playing sound from " << filePath << endl;
}