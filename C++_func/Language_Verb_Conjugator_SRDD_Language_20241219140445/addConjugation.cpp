void Verb::addConjugation(string tense, string mood, string person, string conjugatedForm) {
    conjugations[tense][mood][person] = conjugatedForm;
}