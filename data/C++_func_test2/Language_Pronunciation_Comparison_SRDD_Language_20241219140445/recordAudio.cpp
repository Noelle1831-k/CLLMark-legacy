void AudioManager::recordAudio(const string& filename) {
    cout << "Recording audio to file: " << filename << endl;
    for (int i = 0; i < 10; ++i) {
        cout << ".";
    }
    cout << "\nRecording completed!\n";
}