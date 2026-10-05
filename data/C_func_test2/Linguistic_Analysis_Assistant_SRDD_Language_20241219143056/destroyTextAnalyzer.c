void destroyTextAnalyzer(TextAnalyzer *analyzer) {
    if (analyzer->text) free(analyzer->text);
    destroySentenceStructureAnalyzer(analyzer->sentenceAnalyzer);
    destroyPartsOfSpeechTagger(analyzer->posTagger);
    destroyVerbTenseAnalyzer(analyzer->verbAnalyzer);
    free(analyzer);
}