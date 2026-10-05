void analyze(TextAnalyzer *analyzer) {
    printf("Identifying sentences...\n");
    identifySentences(analyzer->sentenceAnalyzer, analyzer->text);
    printf("Tagging parts of speech...\n");
    tagPartsOfSpeech(analyzer->posTagger, analyzer->text);
    printf("Analyzing verb tenses...\n");
    identifyVerbs(analyzer->verbAnalyzer, analyzer->text);
}