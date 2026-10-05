void GameManager::loadLevel(int level) {
    cout << "Loading Level " << level << "..." << endl;
    dungeon.generateDungeon(level);
    dungeon.displayDungeon();
    printf("Solve the puzzles to proceed!\n");
}