int main() {
    cout << "Welcome to Music Chord Progression Enhancer!\n";
    UserInterface ui;
    ChordAnalyzer analyzer;
    ChordEnhancer enhancer;
    ProgressionGenerator generator;
    vector<string> userChords = ui.getUserInput();
    vector<string> analyzedChords = analyzer.analyzeProgression(userChords);
    vector<string> enhancedChords = enhancer.enhanceProgression(analyzedChords);
    string finalProgression = generator.generateProgression(enhancedChords);
    ui.showResults(finalProgression);
    return 0;
}