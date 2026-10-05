void Character::randomizeStats() {
    for (auto& stat : stats) {
        stat.second = rand() % 100 + 1; 
    }
}