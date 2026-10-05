void SentenceAnalyzer::identifyPartsOfSpeech(const string& sentence) {
    Tokenizer tokenizer;
    POSIdentifier posIdentifier;
    vector<string> tokens = tokenizer.tokenize(sentence);
    for (size_t i = 0; i < tokens.size(); i++) {
        cout << "Token [" << i + 1 << "]: " << tokens[i] << endl;
        posIdentifier.identify(tokens[i]);
    }
}