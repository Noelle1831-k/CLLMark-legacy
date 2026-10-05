void AudioMixer::addTrack(const AudioFile& track) {
    tracks.push_back(track);
    cout << "Track added to mixer." << endl;
}