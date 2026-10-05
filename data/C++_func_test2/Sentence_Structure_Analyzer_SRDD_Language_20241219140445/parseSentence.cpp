void SentenceAnalyzer::parseSentence() {
    tokens = tokenizeString(sentence);
    cout << "Tokenized Sentence: ";
    for (size_t i = 0; i < tokens.size(); i++) {
        cout << tokens[i] << " ";
    }
    cout << endl;
}