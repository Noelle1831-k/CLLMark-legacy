string Verb::getConjugation(string tense, string mood, string person) {
    if (conjugations.find(tense) != conjugations.end() &&
        conjugations[tense].find(mood) != conjugations[tense].end() &&
        conjugations[tense][mood].find(person) != conjugations[tense][mood].end()) {
        return conjugations[tense][mood][person];
    }
    return "Conjugation not found.";
}