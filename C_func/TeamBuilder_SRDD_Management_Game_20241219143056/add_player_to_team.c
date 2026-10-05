void add_player_to_team(Team *t, Player p) {
    if (t->player_count < 11) {
        t->players[t->player_count] = p;
        t->player_count++;
        printf("Player %s added to team %s.\n", p.name, t->team_name);
    } else {
        printf("Team is already full!\n");
    }
}