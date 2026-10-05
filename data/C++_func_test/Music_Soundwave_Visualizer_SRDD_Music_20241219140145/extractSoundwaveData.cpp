vector<float> AudioProcessor::extractSoundwaveData() {
    vector<float> soundwaveData;
    for (size_t i = 0; i < audioData.size(); i = i + 10) {
        float rms = 0.0f;
        for (size_t j = 0; j < 10 && i + j < audioData.size(); j++) {
            rms += audioData[i + j] * audioData[i + j];
        }
        rms = sqrt(rms / 10);
        soundwaveData.push_back(rms);
    }
    return soundwaveData;
}