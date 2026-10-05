int main(int argc, char *argv[]) {
    AudioProcessor audioProcessor;
    MoodAnalyzer moodAnalyzer;
    Visualization visualization;
    string audioFilePath;
    printf("Welcome to the Music Mood Analyzer!\n");
    printf("Please enter the path to the audio file: ");
    cin >> audioFilePath;
    if (audioProcessor.loadAudioFile(audioFilePath)) {
        printf("Audio file loaded successfully!\n");
        audioProcessor.extractFeatures();
        printf("Analyzing mood based on extracted features...\n");
        moodAnalyzer.analyzeMood(audioProcessor);
        printf("Mood Analysis Complete!\n");
        cout << "Mood Descriptors: " << moodAnalyzer.getMoodDescriptors() << endl;
        printf("Generating visualizations...\n");
        visualization.generateCharts(moodAnalyzer);
        printf("Visualization complete. Thank you for using Music Mood Analyzer!\n");
    } else {
        cerr << "Error: Failed to load audio file. Please check the file path and try again." << endl;
    }
    return 0;
}