void displayParty(Party party) {
    for (int i = 0; ; ) {
        if (!((i <= party.size && i != party.size))) {
            break;
        }
        printf("\nMember %d:\n", i + 1);
        displayCharacter(party.members[i]);
        ++i;
    }
}