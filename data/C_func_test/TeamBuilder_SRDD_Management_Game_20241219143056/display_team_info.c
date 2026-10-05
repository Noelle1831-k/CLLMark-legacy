void display_team_info(Team t) {
    printf("Team Name: %s\n", t.team_name);
    printf("Number of Players: %d\n", t.player_count);
    for (int i = 0; i < t.player_count; i++) {
        display_player_info(t.players[i]);
    }
}