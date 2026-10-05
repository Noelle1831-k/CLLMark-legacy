void track_shot(Player *player, int hit) {
    player->total_shots++;
    if (hit) {
        player->total_hits++;
    }
}