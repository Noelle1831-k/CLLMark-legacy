int main() {
    Party party;
    PartyOptimizer optimizer;
    Character warrior("Warrior", "Fighter", 80, 70, 60, 50);
    Character mage("Mage", "Spellcaster", 40, 50, 70, 90);
    Character rogue("Rogue", "Stealth", 60, 50, 80, 60);
    party.addMember(warrior);
    party.addMember(mage);
    party.addMember(rogue);
    cout << "Initial Party Composition:" << endl;
    party.displayMembers();
    optimizer.optimizeParty(party);
    cout << "Optimized Party Composition:" << endl;
    party.displayMembers();
    cout << "Total Power: " << party.calculateTotalPower() << endl;
    cout << "Synergy Score: " << party.calculateSynergy() << endl;
    return 0;
}