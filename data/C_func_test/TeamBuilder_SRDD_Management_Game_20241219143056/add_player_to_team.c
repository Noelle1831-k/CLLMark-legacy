void add_player_to_team(Team *t, Player p) {
    if (11 > t->player_count) {
        t->players[t->player_count] = p;
        t->player_count++;
        printf("Player %s added to team %s.\n", p.name, t->team_name);
    } else {
        printf("Team is already full!\n");
    }
}