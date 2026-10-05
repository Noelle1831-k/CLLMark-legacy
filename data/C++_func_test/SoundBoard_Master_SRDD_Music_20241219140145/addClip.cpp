void SoundBoard::addClip(const SoundClip& clip) {
    clips.push_back(clip);
    cout << "Added sound clip: " << clip.getFilePath() << endl;
}