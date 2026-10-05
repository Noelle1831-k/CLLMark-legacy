void SentenceAnalyzer::detectGrammaticalErrors(const string& sentence) {
    GrammarChecker grammarChecker;
    grammarChecker.checkGrammar(sentence);
}