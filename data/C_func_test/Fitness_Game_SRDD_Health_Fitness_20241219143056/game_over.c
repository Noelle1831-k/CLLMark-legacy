void game_over(Player *player) {
    if (player->score >= 100) {
        printf("Game over! You've earned a total of %d points.\n", player->score);
        award_badge(player, "Game Master");
    }
}