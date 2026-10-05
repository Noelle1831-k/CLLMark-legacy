void PronunciationAnalyzer::analyzePronunciation() {
    cout << "Analyzing pronunciation..." << endl;
    ifstream inputFile("processed_audio.raw", ios::binary);
    ofstream resultFile(analysisResult);
    if (!inputFile || !resultFile) {
        throw runtime_error("Failed to open files for pronunciation analysis.");
    }
    char sample;
    int score = 0;
    while (inputFile.read(&sample, sizeof(sample))) {
        score += static_cast<int>(sample) % 10; 
    }
    resultFile << "Pronunciation Score: " << score << endl;
    inputFile.close();
    resultFile.close();
    cout << "Pronunciation analysis complete. Results saved to " << analysisResult << endl;
}