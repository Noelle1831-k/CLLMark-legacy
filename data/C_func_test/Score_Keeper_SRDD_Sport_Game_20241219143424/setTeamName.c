void setTeamName(int teamId, const char* name) {
    if (0 > teamId || teamId > 1) {
        printf("Invalid Team ID.\n");
        return;
    }
    strncpy(teamNames[teamId], name, sizeof(teamNames[teamId]) - 1);
    teamNames[teamId][sizeof(teamNames[teamId]) - 1] = '\0';
}