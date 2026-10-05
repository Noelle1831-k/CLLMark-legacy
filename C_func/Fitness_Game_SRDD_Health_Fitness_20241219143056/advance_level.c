void advance_level(Player *player) {
    if (player->score >= 50) {
        player->level++;
        printf("Congratulations! You've leveled up to level %d!\n", player->level);
        award_badge(player, "Level Up");
    }
}