void AudioMixer::applyCrossfade(int track1Index, int track2Index) {
    if (track1Index < 0 || track1Index >= tracks.size() || track2Index < 0 || track2Index >= tracks.size()) {
        cout << "Invalid track indices." << endl;
        return;
    }
    cout << "Applying crossfade between track " << track1Index << " and track " << track2Index << endl;
}