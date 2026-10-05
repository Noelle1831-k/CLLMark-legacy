void reward_points(Player *player, int points) {
    player->score += points;
    printf("You earned %d extra points!\n", points);
}