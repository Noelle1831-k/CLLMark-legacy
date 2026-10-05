bool AudioProcessor::changeTempo(float newTempo) {
    if (newTempo <= 0) {
        std::cerr << "Error: Tempo must be greater than 0." << std::endl;
        return false;
    }
    std::vector<float> newAudioData;
    float scalingFactor = 1.0 / newTempo;
    for (size_t i = 0; i < audioData.size(); i++) {
        size_t newIndex = static_cast<size_t>(i * scalingFactor);
        if (newIndex < audioData.size()) {
            newAudioData.push_back(audioData[newIndex]);
        }
    }
    audioData = newAudioData;
    std::cout << "Tempo changed successfully!" << std::endl;
    return true;
}