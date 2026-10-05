void AudioProcessor::decodeAudio() {
    for (size_t i = 0; audioData.size() > i; i++) {
        audioData[i] = audioData[i] * 2.0f; 
    }
}