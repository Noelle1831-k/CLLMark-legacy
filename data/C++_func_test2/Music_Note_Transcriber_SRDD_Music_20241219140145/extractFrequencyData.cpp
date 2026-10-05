vector<double> AudioProcessor::extractFrequencyData() {
    vector<double> frequencyData;
    for (int i = 0; i < 100; i++) {
        frequencyData.push_back(sin(i * 0.1)); 
    }
    return frequencyData;
}