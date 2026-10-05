void GrammarChecker::checkGrammar(const string& text) {
    textAnalyzer.analyzeSentenceStructure(text);
    textAnalyzer.identifyPartsOfSpeech(text);
    textAnalyzer.checkVerbTenses(text);
    errorIdentifier.findSentenceErrors(text);
    errorIdentifier.findPosErrors(text);
    errorIdentifier.findTenseErrors(text);
}