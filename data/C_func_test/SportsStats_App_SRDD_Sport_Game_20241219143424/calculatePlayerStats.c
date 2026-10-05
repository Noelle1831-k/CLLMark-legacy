void calculatePlayerStats() {
    printf("Calculate Player Statistics\n");
    for (int i = 0; i < player_count; i++) {
        printf("Player: %s, Age: %d, Position: %s, Team ID: %d\n", players[i].name, players[i].age, players[i].position, players[i].team_id);
    }
}