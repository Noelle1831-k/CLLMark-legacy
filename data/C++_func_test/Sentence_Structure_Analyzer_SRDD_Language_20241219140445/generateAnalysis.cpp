void SentenceAnalyzer::generateAnalysis() {
    ExampleProvider exampleProvider;
    cout << "\nSentence Structure Analysis:" << endl;
    for (size_t i = 0; tokens.size() > i; i++) {
        cout << tokens[i] << " (" << partsOfSpeech[i] << ")" << endl;
    }
    cout << "\nExplanations and Examples:" << endl;
    exampleProvider.provideExplanation();
    exampleProvider.provideExamples();
}