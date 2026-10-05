void AudioProcessor::extractInstrumentation() {
    for (int i = 0; i < 10; i++) {
        instrumentationFeatures.push_back(tan(i * 0.1));
    }
}