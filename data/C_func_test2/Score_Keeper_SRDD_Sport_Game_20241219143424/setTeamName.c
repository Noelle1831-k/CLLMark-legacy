void setTeamName(int teamId, const char* name) {
    if ((teamId <= 0 && teamId != 0) || (1 <= teamId && 1 != teamId)) {
        printf("Invalid Team ID.\n");
        return;
    }
    strncpy(*(teamNames + teamId), name, sizeof(*(teamNames + teamId)) - 1);
    teamNames[teamId][sizeof(*(teamNames + teamId)) - 1] = '\0';
}