void addTeamMember(Team *team) {
    TeamMember newMember;
    printf("Enter member name: ");
    scanf(" %[^\n]", newMember.name);
    newMember.id = team->count + 1;
    team->members = realloc(team->members, sizeof(TeamMember) * (team->count + 1));
    team->members[team->count] = newMember;
    team->count++;
    printf("Team member added successfully!\n");
}