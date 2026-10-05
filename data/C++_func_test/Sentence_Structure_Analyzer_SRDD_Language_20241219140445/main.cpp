int main() {
    string inputSentence;
    cout << "Welcome to Sentence Structure Analyzer!" << endl;
    cout << "Enter a sentence to analyze: ";
    getline(cin, inputSentence);
    SentenceAnalyzer analyzer(inputSentence);
    analyzer.analyze();
    return 0;
}