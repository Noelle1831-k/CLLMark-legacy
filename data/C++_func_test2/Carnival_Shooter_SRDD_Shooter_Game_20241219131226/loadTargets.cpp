void Level::loadTargets() {
    targets.clear(); 
    for (int i = 0; i < levelNumber * 5; ++i) {
        targets.push_back(Target());
    }
}