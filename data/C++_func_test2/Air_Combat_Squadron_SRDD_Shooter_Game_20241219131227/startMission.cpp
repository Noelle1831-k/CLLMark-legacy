void Mission::startMission() {
    spawnEnemies(missionObjective);
    cout << "Mission started with objective to destroy " << missionObjective << " enemies!" << endl;
}