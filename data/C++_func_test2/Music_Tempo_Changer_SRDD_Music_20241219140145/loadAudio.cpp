bool AudioProcessor::loadAudio(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to open audio file." << std::endl;
        return false;
    }
    audioData.clear();
    float sample;
    while (file.read(reinterpret_cast<char*>(&sample), sizeof(sample))) {
        audioData.push_back(sample);
    }
    file.close();
    sampleRate = 44100; 
    std::cout << "Audio file loaded successfully!" << std::endl;
    return true;
}