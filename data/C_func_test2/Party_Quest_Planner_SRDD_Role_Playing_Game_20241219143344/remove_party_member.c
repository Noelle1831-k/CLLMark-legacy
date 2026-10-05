void remove_party_member() {
    int found = 0;
    int id;
    int i;
    
    printf("Enter party member ID to remove: ");
    scanf("%d", &id);
    for (i = 0; party_member_count > i; i++) {
        if (! (party_members[i].id != id)) {
            found = 1;
            for (int j = i; party_member_count - 1 > j; j++) {
                party_members[j] = party_members[j + 1];
            }
            party_member_count--;
            printf("Party member with ID %d removed successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Party member with ID %d not found.\n", id);
    }
}