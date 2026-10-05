void EchoEffect::applyEcho(AudioFile& audio) {
    vector<float> data = audio.getAudioData();
    int sampleRate = audio.getSampleRate();
    int delaySamples = (int)((delay / 1000.0) * sampleRate);
    for (int i = delaySamples; i < (int)data.size(); ++i) {
        data[i] += data[i - delaySamples] * decay;
    }
    audio.setAudioData(data);
    cout << "Echo effect applied." << endl;
}