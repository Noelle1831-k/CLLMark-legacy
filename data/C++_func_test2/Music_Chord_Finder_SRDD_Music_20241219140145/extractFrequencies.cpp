void AudioProcessor::extractFrequencies() {
    int i;
    for (i = 0; i < 100; i++) {
        frequencyData.push_back(sin(i) * 440.0); 
    }
}