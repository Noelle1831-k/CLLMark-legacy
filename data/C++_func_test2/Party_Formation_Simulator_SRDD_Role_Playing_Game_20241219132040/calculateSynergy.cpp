int Party::calculateSynergy() {
    int synergy = 0;
    for (size_t i = 0; i < characters.size(); ++i) {
        for (size_t j = i + 1; j < characters.size(); ++j) {
            synergy += abs(characters[i].calculateCombatEffectiveness() - characters[j].calculateCombatEffectiveness());
        }
    }
    return synergy;
}