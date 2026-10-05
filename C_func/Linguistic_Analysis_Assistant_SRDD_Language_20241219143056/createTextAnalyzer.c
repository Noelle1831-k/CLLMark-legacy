TextAnalyzer* createTextAnalyzer() {
    TextAnalyzer *analyzer = (TextAnalyzer*)malloc(sizeof(TextAnalyzer));
    analyzer->text = NULL;
    analyzer->sentenceAnalyzer = createSentenceStructureAnalyzer();
    analyzer->posTagger = createPartsOfSpeechTagger();
    analyzer->verbAnalyzer = createVerbTenseAnalyzer();
    return analyzer;
}