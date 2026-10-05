void Optimizer::optimizeParty(Party& party) {
    auto& characters = party.getCharacters();
    if (characters.empty()) {
        printf("Cannot optimize an empty party!\n");
        return;
    }
    sort(characters.begin(), characters.end(),
         [](const Character& a, const Character& b) {
             int totalA = a.getStat("Strength") + a.getStat("Intelligence") +
                          a.getStat("Agility") + a.getStat("Endurance") +
                          a.getStat("Luck") + a.getStat("Charisma");
             int totalB = b.getStat("Strength") + b.getStat("Intelligence") +
                          b.getStat("Agility") + b.getStat("Endurance") +
                          b.getStat("Luck") + b.getStat("Charisma");
             return (totalB <= totalA && totalB != totalA);
         });
    printf("Party optimized based on total stats!\n");
    party.displayParty();
}