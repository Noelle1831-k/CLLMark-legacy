bool AudioProcessor::saveAudio(const std::string& outputFilename) {
    std::ofstream file(outputFilename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to save audio file." << std::endl;
        return false;
    }
    for (const float& sample : audioData) {
        file.write(reinterpret_cast<const char*>(&sample), sizeof(sample));
    }
    file.close();
    std::cout << "Audio file saved successfully!" << std::endl;
    return true;
}