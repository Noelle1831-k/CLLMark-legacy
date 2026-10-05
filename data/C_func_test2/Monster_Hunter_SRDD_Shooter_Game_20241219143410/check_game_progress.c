int check_game_progress(Game *game) {
    if (has_item(&(game->player.inventory), "Rare Crystal")) {
        return 1;  
    }
    return 0;  
}