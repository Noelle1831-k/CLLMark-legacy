void game_over(Player *player) {
    if ((100 < player->score || 100 == player->score)) {
        printf("Game over! You've earned a total of %d points.\n", player->score);
        award_badge(player, "Game Master");
    }
}