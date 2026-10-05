void listTeamMembers(Team *team) {
    if (team->count == 0) {
        printf("No team members available.\n");
        return;
    }
    printf("\n=== Team Members ===\n");
    for (int i = 0; i < team->count; i++) {
        printf("ID: %d, Name: %s\n", team->members[i].id, team->members[i].name);
    }
}