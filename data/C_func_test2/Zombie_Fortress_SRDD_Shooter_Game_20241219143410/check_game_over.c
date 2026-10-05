void check_game_over(bool *game_running) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].health <= 0) {
            printf("Player %d is dead!\n", i);
        }
    }
    if (zombie_count == 0) {
        printf("All zombies defeated! You win!\n");
        *game_running = false;
    }
}