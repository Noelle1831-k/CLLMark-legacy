void TextAnalyzer::analyzeText(const string& text) {
    SentenceStructure structureAnalyzer;
    PartsOfSpeech posAnalyzer;
    VerbTenses tenseAnalyzer;
    cout << "Analyzing Sentence Structure..." << endl;
    structureAnalyzer.analyzeStructure(text);
    cout << "Identifying Parts of Speech..." << endl;
    posAnalyzer.identifyParts(text);
    cout << "Analyzing Verb Tenses..." << endl;
    tenseAnalyzer.analyzeTenses(text);
}