void AudioFile::saveFile(const string& outputFileName) {
    SF_INFO sfinfo;
    sfinfo.channels = 1;
    sfinfo.samplerate = 44100;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    SNDFILE *file = sf_open(outputFileName.c_str(), SFM_WRITE, &sfinfo);
    if (!file) {
        cout << "Failed to save file: " << outputFileName << endl;
        return;
    }
    sf_write_float(file, &audioData[0], audioData.size());
    sf_close(file);
    cout << "Saved audio file to: " << outputFileName << endl;
}