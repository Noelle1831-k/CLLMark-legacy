void PartyOptimizer::generateOptimalParty(Party &party) {
    vector<Character> characters = party.getCharacters();
    sort(characters.begin(), characters.end(),
         [](Character &a, Character &b) { return a.calculateCombatEffectiveness() > b.calculateCombatEffectiveness(); });
    cout << "Optimal Party Formation:" << endl;
    for (auto &character : characters) {
        cout << character.getName() << " (" << character.getClass() << ") - Combat Effectiveness: "
             << character.calculateCombatEffectiveness() << endl;
    }
}