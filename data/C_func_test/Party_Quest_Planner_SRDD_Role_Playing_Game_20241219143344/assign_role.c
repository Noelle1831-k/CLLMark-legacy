void assign_role() {
    int id, found = 0;
    printf("Enter party member ID to assign a role: ");
    scanf("%d", &id);
    for (int i = 0; i < party_member_count; i++) {
        if (party_members[i].id == id) {
            found = 1;
            printf("Enter new role for %s: ", party_members[i].name);
            scanf(" %[^\n]s", party_members[i].role);
            printf("Role assigned successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Party member with ID %d not found.\n", id);
    }
}