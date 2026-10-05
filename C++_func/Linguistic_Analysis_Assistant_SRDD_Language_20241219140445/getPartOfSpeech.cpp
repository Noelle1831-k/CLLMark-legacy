string PartsOfSpeech::getPartOfSpeech(const string& word) {
    if (word == "the" || word == "a" || word == "an") {
        return "Article";
    } else if (word == "jumps" || word == "was") {
        return "Verb";
    } else if (word == "quick" || word == "brown" || word == "lazy" || word == "sunny") {
        return "Adjective";
    } else if (word == "fox" || word == "dog" || word == "day") {
        return "Noun";
    } else {
        return "Unknown";
    }
}