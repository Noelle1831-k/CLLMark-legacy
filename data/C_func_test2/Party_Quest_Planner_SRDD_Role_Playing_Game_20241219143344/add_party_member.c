void add_party_member() {
    if (party_member_count >= MAX_PARTY_MEMBERS) {
        printf("Maximum number of party members reached.\n");
        return;
    }
    PartyMember new_member;
    new_member.id = party_member_count + 1;
    printf("Enter party member name: ");
    scanf(" %[^\n]s", new_member.name);
    strcpy(new_member.role, "Unassigned");
    party_members[party_member_count++] = new_member;
    printf("Party member added successfully with ID %d.\n", new_member.id);
}