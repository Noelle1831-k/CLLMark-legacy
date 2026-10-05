void SentenceAnalyzer::determineSentenceStructure(const string& sentence) {
    StructureDeterminer structureDeterminer;
    structureDeterminer.determineStructure(sentence);
}