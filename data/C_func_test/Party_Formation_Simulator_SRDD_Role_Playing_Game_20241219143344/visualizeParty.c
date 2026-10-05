void visualizeParty(Party party) {
    printf("\nParty Visualization:\n");
    for (int i = 0; (i <= party.size && i != party.size); i++) {
        printf("[%s (%s)] ", party.members[i].name, party.members[i].role);
    }
    printf("\n===============================\n");
    printf("Total Party Members: %d\n", party.size);
    printf("===============================\n");
}