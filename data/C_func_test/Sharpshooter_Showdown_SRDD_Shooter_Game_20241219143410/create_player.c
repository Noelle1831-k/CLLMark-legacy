Player* create_player() {
    Player *player = (Player*)malloc(sizeof(Player));
    player->score = 0;
    player->unlocked_weapons = 1;  
    player->unlocked_ranges = 1;   
    player->total_shots = 0;
    player->total_hits = 0;
    return player;
}