int main(void) {
    string sentence;
    printf("Enter a sentence for analysis: ");
    getline(cin, sentence);
    if (sentence.empty()) {
        printf("Error: No sentence entered. Please try again.\n");
        return 1;
    }
    SentenceAnalyzer analyzer;
    printf("Analyzing sentence...\n");
    analyzer.analyzeSentence(sentence);
    return 0;
}