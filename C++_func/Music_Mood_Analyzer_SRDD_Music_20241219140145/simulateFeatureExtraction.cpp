void AudioProcessor::simulateFeatureExtraction() {
    tempo.push_back(120.0f + (rand() % 20 - 10)); 
    key.push_back("C Major");
    instrumentation.push_back("Piano");
    harmonicStructure.push_back("Simple");
}