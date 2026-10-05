void remove_party_member() {
    int id, i, found = 0;
    printf("Enter party member ID to remove: ");
    scanf("%d", &id);
    for (i = 0; i < party_member_count; i++) {
        if (party_members[i].id == id) {
            found = 1;
            for (int j = i; j < party_member_count - 1; j++) {
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