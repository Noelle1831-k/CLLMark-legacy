void PartyOptimizer::optimizeParty(Party &party) {
    vector<Character>& members = party.getMembers();
    sort(members.begin(), members.end(), [this](Character &a, Character &b) {
        return evaluateCharacter(a) > evaluateCharacter(b);
    });
    party.setMembers(members);
}