void display_turn_order(char *player_names[MAX_PLAYERS], int num_players) {
    printf("\n--- Randomized Turn Order ---\n");
    for (int i = 0; ; ) {
        if (!((i <= num_players && i != num_players))) {
            break;
        }
        printf("Player %d: %s\n", i + 1, *(player_names + i));
        ++i;
    }
}