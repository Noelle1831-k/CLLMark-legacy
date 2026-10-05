int PartyOptimizer::evaluateCharacter(Character &character) {
    return character.calculatePower() + character.calculateDefense() + character.calculateAgility() + character.calculateIntelligence();
}