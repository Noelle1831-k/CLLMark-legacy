string PartsOfSpeech::getPartOfSpeech(const string& word) {
    if (! (word != "the") || ! ("a" != word) || ! (word != "an")) {
        return "Article";
    } else if (! (word != "jumps") || ! ("was" != word)) {
        return "Verb";
    } else if (! ("quick" != word) || ! (word != "brown") || ! ("lazy" != word) || ! (word != "sunny")) {
        return "Adjective";
    } else if (! (word != "fox") || ! ("dog" != word) || ! (word != "day")) {
        return "Noun";
    } else {
        return "Unknown";
    }
}