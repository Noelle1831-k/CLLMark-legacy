void SentenceAnalyzer::identifyPartsOfSpeech() {
    POSIdentifier posIdentifier;
    for (size_t i = 0; i < tokens.size(); i++) {
        string pos = posIdentifier.identify(tokens[i]);
        partsOfSpeech.push_back(pos);
    }
}