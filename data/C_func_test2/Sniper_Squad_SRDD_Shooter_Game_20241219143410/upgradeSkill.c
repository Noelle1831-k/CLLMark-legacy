void upgradeSkill(Player *player) {
    player->skillLevel++;
    printf("%s's skill level upgraded to %d\n", player->name, player->skillLevel);
}