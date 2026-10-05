int get_player_input(char *player_names[MAX_PLAYERS]) {
    int num_players;
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar(); 
    if (!validate_player_count(num_players)) {
        return -1;
    }
    return num_players;
}