vector<float> AudioProcessor::extractFeatures() {
    extractRhythm();
    extractMelody();
    extractInstrumentation();
    vector<float> features;
    features.insert(features.end(), rhythmFeatures.begin(), rhythmFeatures.end());
    features.insert(features.end(), melodyFeatures.begin(), melodyFeatures.end());
    features.insert(features.end(), instrumentationFeatures.begin(), instrumentationFeatures.end());
    return features;
}