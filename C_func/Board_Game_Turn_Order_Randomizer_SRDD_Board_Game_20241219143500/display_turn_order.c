void display_turn_order(char *player_names[MAX_PLAYERS], int num_players) {
    printf("\n--- Randomized Turn Order ---\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %s\n", i + 1, player_names[i]);
    }
}