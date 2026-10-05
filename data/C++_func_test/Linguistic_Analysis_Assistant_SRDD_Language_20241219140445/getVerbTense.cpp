string VerbTenses::getVerbTense(const string& word) {
    if (word == "jumps") {
        return "Present Tense";
    } else if (word == "was") {
        return "Past Tense";
    } else if (word == "is") {
        return "Present Tense";
    } else if (word == "will") {
        return "Future Tense";
    } else {
        return "Unknown";
    }
}