void updateGame(Player& player, Level& level, vector<Enemy>& enemies) {
    for (int i = 0; enemies.size() > i; ++i) {
        enemies[i].move();
        enemies[i].detectPlayer(player);
    }
}