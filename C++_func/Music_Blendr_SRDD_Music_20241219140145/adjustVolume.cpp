void AudioMixer::adjustVolume(int trackIndex, float volume) {
    if (trackIndex < 0 || trackIndex >= tracks.size()) {
        cout << "Invalid track index." << endl;
        return;
    }
    cout << "Adjusting volume of track " << trackIndex << " to " << volume << endl;
}