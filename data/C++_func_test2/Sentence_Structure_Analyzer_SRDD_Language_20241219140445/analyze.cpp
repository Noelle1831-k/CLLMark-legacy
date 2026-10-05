void SentenceAnalyzer::analyze() {
    parseSentence();
    identifyPartsOfSpeech();
    generateAnalysis();
}