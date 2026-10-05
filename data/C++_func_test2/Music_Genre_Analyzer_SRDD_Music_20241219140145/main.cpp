int main() {
    UserInterface ui;
    AudioProcessor audioProcessor;
    GenreClassifier genreClassifier;
    cout << "Welcome to the Music Genre Analyzer!" << endl;
    string inputFilePath = ui.getUserInput();
    if (!audioProcessor.loadAudioFile(inputFilePath)) {
        cerr << "Error: Unable to load the audio file." << endl;
        return -1;
    }
    vector<float> features = audioProcessor.extractFeatures();
    if (!genreClassifier.loadPretrainedModel("model_data.dat")) {
        cerr << "Error: Unable to load the pre-trained model." << endl;
        return -1;
    }
    string predictedGenre = genreClassifier.predictGenre(features);
    float confidenceScore = genreClassifier.calculateConfidence(features);
    ui.displayResults(predictedGenre, confidenceScore);
    return 0;
}