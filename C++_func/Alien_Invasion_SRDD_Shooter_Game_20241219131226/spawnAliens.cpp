void Level::spawnAliens() {
    alienCount = rand() % 10 + 1; 
    cout << alienCount << " aliens spawned in Level " << levelNumber << "!" << endl;
}