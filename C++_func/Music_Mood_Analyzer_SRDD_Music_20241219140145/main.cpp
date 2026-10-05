int main() {
    AudioProcessor audioProcessor;
    MoodAnalyzer moodAnalyzer;
    Visualization visualization;
    string audioFilePath;
    cout << "Welcome to the Music Mood Analyzer!" << endl;
    cout << "Please enter the path to the audio file: ";
    cin >> audioFilePath;
    if (audioProcessor.loadAudioFile(audioFilePath)) {
        cout << "Audio file loaded successfully!" << endl;
        audioProcessor.extractFeatures();
        cout << "Analyzing mood based on extracted features..." << endl;
        moodAnalyzer.analyzeMood(audioProcessor);
        cout << "Mood Analysis Complete!" << endl;
        cout << "Mood Descriptors: " << moodAnalyzer.getMoodDescriptors() << endl;
        cout << "Generating visualizations..." << endl;
        visualization.generateCharts(moodAnalyzer);
        cout << "Visualization complete. Thank you for using Music Mood Analyzer!" << endl;
    } else {
        cerr << "Error: Failed to load audio file. Please check the file path and try again." << endl;
    }
    return 0;
}