int main() {
    string sentence;
    cout << "Enter a sentence for analysis: ";
    getline(cin, sentence);
    if (sentence.empty()) {
        cout << "Error: No sentence entered. Please try again." << endl;
        return 1;
    }
    SentenceAnalyzer analyzer;
    cout << "Analyzing sentence..." << endl;
    analyzer.analyzeSentence(sentence);
    return 0;
}