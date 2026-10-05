void AudioFile::loadFile() {
    SF_INFO sfinfo;
    SNDFILE *file = sf_open(fileName.c_str(), SFM_READ, &sfinfo);
    if (!file) {
        cout << "Failed to open file: " << fileName << endl;
        return;
    }
    audioData.resize(sfinfo.frames * sfinfo.channels);
    sf_read_float(file, &audioData[0], audioData.size());
    sf_close(file);
    cout << "Loaded audio file: " << fileName << endl;
}