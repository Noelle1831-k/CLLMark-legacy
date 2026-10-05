void AudioProcessor::decodeAudio() {
    for (size_t i = 0; i < audioData.size(); i++) {
        audioData[i] *= 2.0f; 
    }
}