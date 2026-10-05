void increaseDifficulty(Game *game) {
    if (game->score % 100 == 0) {
        game->level++;
        for (int i = 0; i < MAX_ALIENS; i++) {
            game->aliens[i].speed += 1;
        }
    }
}