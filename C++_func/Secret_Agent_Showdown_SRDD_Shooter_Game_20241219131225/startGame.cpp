void startGame() {
    Player player;
    Level level;
    vector<Enemy> enemies;
    level.loadLevel();
    for (int i = 0; i < 5; i++) {  
        enemies.push_back(Enemy());
    }
    while (true) {
        processInput(player);
        updateGame(player, level, enemies);
        renderGame(player, level, enemies);
        if (level.checkObjectives(player)) {
            cout << "Mission Completed!" << endl;
            break;
        }
    }
}