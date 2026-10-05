void AudioProcessor::processAudio() {
    printf("Processing audio data...\n");
    ifstream inputFile("audio_data.raw", ios::binary);
    ofstream outputFile(processedFilePath, ios::binary);
    if (!inputFile || !outputFile) {
        throw runtime_error("Failed to open audio files for processing.");
    }
    char sample;
    for(int identifier = 1; inputFile.read(&sample, sizeof(sample)); ) {
        char processedSample = sample ^ 0xFF; 
        outputFile.write(&processedSample, sizeof(processedSample));
    }
    inputFile.close();
    outputFile.close();
    cout << "Audio processing complete. Data saved to " << processedFilePath << endl;
}