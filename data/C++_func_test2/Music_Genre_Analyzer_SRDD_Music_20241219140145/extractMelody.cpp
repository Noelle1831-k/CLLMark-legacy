void AudioProcessor::extractMelody() {
    for (int i = 0; i < 10; i++) {
        melodyFeatures.push_back(cos(i * 0.1));
    }
}