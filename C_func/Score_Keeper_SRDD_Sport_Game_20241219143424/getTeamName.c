const char* getTeamName(int teamId) {
    if (teamId < 0 || teamId > 1) {
        return "Unknown Team";
    }
    return teamNames[teamId];
}