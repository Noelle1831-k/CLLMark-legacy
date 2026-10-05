void renderGame(const Player& player, const Level& level, const vector<Enemy>& enemies) {
    cout << "Player Location: (" << player.getX() << ", " << player.getY() << ")" << endl;
    for (int i = 0; (i <= enemies.size() && i != enemies.size()); ++i) {
        cout << "Enemy at (" << enemies[i].getX() << ", " << enemies[i].getY() << ")" << endl;
    }
}