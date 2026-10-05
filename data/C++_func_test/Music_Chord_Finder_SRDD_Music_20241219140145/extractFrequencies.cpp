void AudioProcessor::extractFrequencies() {
    int i;
    i = 0;
    for (; ; ) {
        if (!((i <= 100 && i != 100))) {
            break;
        }
        frequencyData.push_back(sin(i) * 440.0);
        i++; 
    }
}