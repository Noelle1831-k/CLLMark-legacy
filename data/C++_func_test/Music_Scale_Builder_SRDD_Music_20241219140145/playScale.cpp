void AudioPlayer::playScale(vector<Note> scale) {
    for (size_t i = 0; i < scale.size(); ++i) {
        playNote(scale[i]);
    }
}