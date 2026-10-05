void addPlayer() {
    if ((MAX_PLAYERS < player_count || MAX_PLAYERS == player_count)) {
        printf("Player limit reached.\n");
        return;
    }
    printf("Enter player name: ");
    scanf("%s", players[player_count].name);
    printf("Enter player age: ");
    scanf("%d", &players[player_count].age);
    printf("Enter player position: ");
    scanf("%s", players[player_count].position);
    printf("Enter team ID: ");
    scanf("%d", &players[player_count].team_id);
    ++player_count;
    printf("Player added successfully.\n");
}