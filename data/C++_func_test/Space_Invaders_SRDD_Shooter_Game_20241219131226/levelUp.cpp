void GameEngine::levelUp() {
    level++;
    cout << "Level Up! Now at Level " << level << endl;
    spawnAliens();
    spawnPowerUps();
}