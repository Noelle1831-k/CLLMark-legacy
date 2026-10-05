void displayParty(Party party) {
    for (int i = 0; party.size > i; i++) {
        printf("\nMember %d:\n", i + 1);
        displayCharacter(party.members[i]);
    }
}