void updateGame(Player& player, Level& level, vector<Enemy>& enemies) {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].move();
        enemies[i].detectPlayer(player);
    }
}