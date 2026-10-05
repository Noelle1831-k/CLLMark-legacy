int get_accuracy(Player *player) {
    if (player->total_shots == 0) return 0;
    return (player->total_hits * 100) / player->total_shots;
}