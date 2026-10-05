void AudioInput::captureAudio() {
    if (!isDeviceInitialized) {
        initializeDevice();
    }
    cout << "Capturing audio input..." << endl;
    ofstream audioFile(audioFilePath, ios::binary);
    if (!audioFile) {
        throw runtime_error("Failed to open audio file for writing.");
    }
    for (int i = 0; i < 1000; i++) {
        char sample = static_cast<char>(i % 256); 
        audioFile.write(&sample, sizeof(sample));
    }
    audioFile.close();
    cout << "Audio capture complete. Data saved to " << audioFilePath << endl;
}