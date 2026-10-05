int main() {
    try {
        cout << "Initializing Language Pronunciation Analyzer..." << endl;
        AudioInput audioInput;
        AudioProcessor audioProcessor;
        PronunciationAnalyzer pronunciationAnalyzer;
        ResultGenerator resultGenerator;
        cout << "Starting audio capture..." << endl;
        audioInput.captureAudio();
        cout << "Starting audio processing..." << endl;
        audioProcessor.processAudio();
        cout << "Starting pronunciation analysis..." << endl;
        pronunciationAnalyzer.analyzePronunciation();
        cout << "Generating analysis report..." << endl;
        resultGenerator.generateReport();
        cout << "Language Pronunciation Analyzer completed successfully!" << endl;
    } catch (const exception &e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
    return 0;
}