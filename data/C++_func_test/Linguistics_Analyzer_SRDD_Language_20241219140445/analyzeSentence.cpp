void SentenceAnalyzer::analyzeSentence(const string& sentence) {
    vector<string> tokens = tokenizeSentence(sentence);
    cout << "\nIdentifying Parts of Speech..." << endl;
    identifyPartsOfSpeech(sentence);
    cout << "\nDetermining Sentence Structure..." << endl;
    determineSentenceStructure(sentence);
    cout << "\nDetecting Grammatical Errors..." << endl;
    detectGrammaticalErrors(sentence);
}