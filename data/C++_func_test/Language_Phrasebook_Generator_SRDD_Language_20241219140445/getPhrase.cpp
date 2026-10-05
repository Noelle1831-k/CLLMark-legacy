Phrase Phrasebook::getPhrase(int index) {
    if (index >= 0 && index < phrases.size()) {
        return phrases[index];
    }
    return Phrase(); 
}