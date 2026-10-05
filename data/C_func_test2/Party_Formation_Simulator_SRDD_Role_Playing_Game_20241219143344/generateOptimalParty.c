Party generateOptimalParty(Character *characters, int numCharacters) {
    Party party;
    party.members = (Character *)malloc(4 * sizeof(Character));
    party.size = 4;
    if (!party.members) {
        fprintf(stderr, "Memory allocation failed for party members.\n");
        exit(1);
    }
    sortCharactersByStrength(characters, numCharacters);
    int count = 0;
    for (int i = 0; i < numCharacters && count < 4; i++) {
        if (strcmp(characters[i].role, "Tank") == 0 ||
            strcmp(characters[i].role, "DPS") == 0 ||
            strcmp(characters[i].role, "Support") == 0) {
            party.members[count++] = characters[i];
        }
    }
    for (int i = 0; count < 4; i++) {
        party.members[count++] = characters[i];
    }
    return party;
}