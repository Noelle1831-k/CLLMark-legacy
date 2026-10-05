int main() {
    srand((unsigned int)time(NULL));
    printf("Initializing Survival Showdown...\n");
    init_player();
    init_arena();
    init_enemies(MAX_ENEMIES);
    init_powerups(MAX_POWERUPS);
    while (!is_game_over()) {
        update_game();
        render_game();
        delay(30);
    }
    printf("Game Over! Your final score: %d\n", get_player_score());
    cleanup_game();
    return 0;
}