void AudioProcessor::extractRhythm() {
    for (int i = 0; i < 10; i++) {
        rhythmFeatures.push_back(sin(i * 0.1));
    }
}