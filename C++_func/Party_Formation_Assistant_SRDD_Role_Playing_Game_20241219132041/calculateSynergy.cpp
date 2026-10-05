int Party::calculateSynergy() {
    int synergy = 0;
    for (size_t i = 0; i < members.size(); i++) {
        synergy += members[i].calculateAgility() + members[i].calculateIntelligence();
    }
    return synergy;
}