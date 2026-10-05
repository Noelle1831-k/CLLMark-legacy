int main(int argc, char *argv[]) {
    try {
        printf("Initializing Language Pronunciation Analyzer...\n");
        AudioInput audioInput;
        AudioProcessor audioProcessor;
        PronunciationAnalyzer pronunciationAnalyzer;
        ResultGenerator resultGenerator;
        printf("Starting audio capture...\n");
        audioInput.captureAudio();
        printf("Starting audio processing...\n");
        audioProcessor.processAudio();
        printf("Starting pronunciation analysis...\n");
        pronunciationAnalyzer.analyzePronunciation();
        printf("Generating analysis report...\n");
        resultGenerator.generateReport();
        printf("Language Pronunciation Analyzer completed successfully!\n");
    } catch (const exception &e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
    return 0;
}