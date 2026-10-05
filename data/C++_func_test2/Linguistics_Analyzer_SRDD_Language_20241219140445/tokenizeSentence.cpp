vector<string> SentenceAnalyzer::tokenizeSentence(const string& sentence) {
    Tokenizer tokenizer;
    return tokenizer.tokenize(sentence);
}