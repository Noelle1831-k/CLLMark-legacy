void shoot(Player* player, Target* target, int x, int y) {
    if (isHit(target, x, y)) {
        printf("Hit! You've successfully hit the target.\n");
        player->score += 10;
    } else {
        printf("Miss! Better luck next time.\n");
    }
}