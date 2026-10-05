Team create_team(char *team_name) {
    Team new_team;
    strcpy(new_team.team_name, team_name);
    new_team.player_count = 0;
    return new_team;
}