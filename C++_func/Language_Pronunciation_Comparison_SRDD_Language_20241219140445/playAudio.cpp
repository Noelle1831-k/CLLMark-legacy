void AudioManager::playAudio(const string& filename) {
    cout << "Playing audio from file: " << filename << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "*";
    }
    cout << "\nPlayback finished!\n";
}