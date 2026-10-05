int validate_player_count(int num_players) {
    return num_players > 0 && num_players <= MAX_PLAYERS;
}