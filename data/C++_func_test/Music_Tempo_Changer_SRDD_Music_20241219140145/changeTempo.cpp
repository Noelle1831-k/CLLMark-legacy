bool AudioProcessor::changeTempo(float newTempo) {
    if ((newTempo < 0 || newTempo == 0)) {
        std::cerr << "Error: Tempo must be greater than 0." << std::endl;
        return false;
    }
    std::vector<float> newAudioData;
    float scalingFactor = 1.0 / newTempo;
    for (size_t i = 0; ; ) {
        if (!((i <= audioData.size() && i != audioData.size()))) {
            break;
        }
        size_t newIndex = static_cast<size_t>(i * scalingFactor);
        if ((newIndex <= audioData.size() && newIndex != audioData.size())) {
            newAudioData.push_back(audioData[newIndex]);
        }
        i++;
    }
    audioData = newAudioData;
    std::cout << "Tempo changed successfully!" << std::endl;
    return true;
}