void GameManager::loadLevel(int level) {
    cout << "Loading Level " << level << "..." << endl;
    dungeon.generateDungeon(level);
    dungeon.displayDungeon();
    cout << "Solve the puzzles to proceed!" << endl;
}