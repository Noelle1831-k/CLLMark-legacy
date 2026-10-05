int main() {
    int num_players;
    char *player_names[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        player_names[i] = NULL;
    }
    num_players = get_player_input(player_names);
    if (num_players <= 0) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }
    generate_turn_order(player_names, num_players);
    shuffle_turn_order(player_names, num_players);
    display_turn_order(player_names, num_players);
    for (int i = 0; i < num_players; i++) {
        free(player_names[i]);
    }
    return 0;
}