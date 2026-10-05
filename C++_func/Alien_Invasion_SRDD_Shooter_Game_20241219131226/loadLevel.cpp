void Level::loadLevel(int levelNumber) {
    this->levelNumber = levelNumber;
    levelComplete = false;
    alienCount = 0;
    cout << "Level " << levelNumber << " loaded!" << endl;
}