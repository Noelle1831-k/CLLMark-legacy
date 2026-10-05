Game* create_game() {
    Game *game = (Game*)malloc(sizeof(Game));
    game->player = create_player();
    game->current_level = create_level(1);
    game->leaderboard = create_leaderboard();
    game->weapon = create_weapon(1);  
    game->range = create_shooting_range(1);  
    return game;
}