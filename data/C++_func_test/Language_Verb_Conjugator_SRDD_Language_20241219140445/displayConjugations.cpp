void Verb::displayConjugations() {
    for (const auto& tense : conjugations) {
        for (const auto& mood : tense.second) {
            for (const auto& person : mood.second) {
                cout << setw(10) << tense.first 
                     << setw(15) << mood.first 
                     << setw(10) << person.first 
                     << ": " << person.second << endl;
            }
        }
    }
}