Game initialize_game() {
    Game game;
    game.is_running = 1;
    game.funds = 1000;
    game.volunteers = 5;
    game.animals_rescued = 0;
    game.community_support = 0;
    return game;
}