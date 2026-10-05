int Character::calculateCombatEffectiveness() {
    combatEffectiveness = 0;
    for (auto &skill : skills) {
        combatEffectiveness += skill.second * 2;
    }
    for (auto &ability : abilities) {
        combatEffectiveness += ability.second * 3;
    }
    return combatEffectiveness;
}